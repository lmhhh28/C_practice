#include <iostream>
#include <memory>
#include <functional>
#include <tuple>
#include <stdexcept>
#include <cstddef>
#include <vector>

class RecursiveStack {
public:
    // 状态枚举
    enum class State {
        Start,         // 初始状态
        AfterRecurse   // 递归调用返回后的状态
    };

    // 帧结构
    struct Frame {
        Frame* prev;
        State state;
        std::function<void(RecursiveStack&)> func;
        std::tuple<> args; // 实际参数存储
    };

    RecursiveStack(size_t stack_size) 
        : stack_memory(std::make_unique<uint8_t[]>(stack_size)),
          stack_ptr(stack_memory.get()),
          stack_end(stack_ptr + stack_size),
          current_frame(nullptr) {}
    
    // 启动调用
    template <typename Func, typename... Args>
    void call(Func&& func, Args&&... args) {
        Frame* frame = allocate_frame<Func, Args...>();
        frame->prev = current_frame;
        frame->state = State::Start;
        
        // 保存函数和参数
        new (&frame->func) std::function<void(RecursiveStack&)>(
            [f = std::forward<Func>(func), args...](RecursiveStack& stack) mutable {
                f(stack, args...);
            }
        );
        
        current_frame = frame;
    }
    
    // 递归调用
    template <typename Func, typename... Args>
    void recurse(Func&& func, Args&&... args) {
        Frame* new_frame = allocate_frame<Func, Args...>();
        new_frame->prev = current_frame;
        new_frame->state = State::Start;
        
        // 保存函数和参数
        new (&new_frame->func) std::function<void(RecursiveStack&)>(
            [f = std::forward<Func>(func), args...](RecursiveStack& stack) mutable {
                f(stack, args...);
            }
        );
        
        // 设置当前帧的状态为 AfterRecurse
        current_frame->state = State::AfterRecurse;
        
        // 切换到新帧
        current_frame = new_frame;
    }
    
    // 从调用返回
    void return_from_call() {
        if (!current_frame) return;
        
        // 销毁当前帧的函数对象
        current_frame->func.~function();
        
        // 弹出当前帧
        Frame* prev_frame = current_frame->prev;
        stack_ptr = reinterpret_cast<uint8_t*>(current_frame);
        current_frame = prev_frame;
    }
    
    // 执行当前帧
    void execute() {
        if (!current_frame) return;
        
        // 执行当前帧的函数
        current_frame->func(*this);
    }
    
    // 检查是否完成
    bool done() const {
        return current_frame == nullptr;
    }
    
    // 获取当前帧的用户数据
    template <typename T>
    T* get_frame_data() {
        return reinterpret_cast<T*>(current_frame + 1);
    }
    
    ~RecursiveStack() {
        // 清理所有未完成的帧
        while (current_frame) {
            return_from_call();
        }
    }

private:
    // 分配帧内存
    template <typename Func, typename... Args>
    Frame* allocate_frame() {
        // 计算所需内存大小
        constexpr size_t frame_size = sizeof(Frame);
        constexpr size_t func_size = sizeof(std::function<void(RecursiveStack&)>);
        constexpr size_t args_size = sizeof(std::tuple<Args...>);
        constexpr size_t total_size = frame_size + func_size + args_size;
        
        // 确保内存对齐
        size_t space = stack_end - stack_ptr;
        void* ptr = stack_ptr;
        if (std::align(alignof(Frame), total_size, ptr, space)) {
            Frame* frame = new (ptr) Frame();
            stack_ptr = static_cast<uint8_t*>(ptr) + total_size;
            return frame;
        }
        
        throw std::runtime_error("Stack overflow");
    }

    std::unique_ptr<uint8_t[]> stack_memory;
    uint8_t* stack_ptr;
    uint8_t* stack_end;
    Frame* current_frame;
};

// ================= 使用示例 =================

// 阶乘计算的帧数据
struct FactorialData {
    int n;
    int result;
};

// 阶乘实现
void factorial(RecursiveStack& stack, int n) {
    // 获取当前帧的数据存储
    auto* data = stack.get_frame_data<FactorialData>();
    data->n = n;
    
    if (n <= 1) {
        data->result = 1;
        stack.return_from_call();
        return;
    }
    
    // 递归调用
    stack.recurse(factorial, n - 1);
}

// 阶乘包装函数
int compute_factorial(int n) {
    // 创建递归栈 (1MB 内存)
    RecursiveStack stack(1024 * 1024);
    
    // 启动调用
    stack.call(factorial, n);
    
    // 执行直到完成
    while (!stack.done()) {
        stack.execute();
    }
    
    // 返回结果
    return stack.get_frame_data<FactorialData>()->result;
}

// 测试深层递归
void deep_recursion(RecursiveStack& stack, int depth) {
    auto* data = stack.get_frame_data<int>();
    *data = depth;
    
    if (depth % 1000 == 0) {
        std::cout << "Current depth: " << depth << std::endl;
    }
    
    if (depth <= 0) {
        stack.return_from_call();
        return;
    }
    
    // 递归调用
    stack.recurse(deep_recursion, depth - 1);
}

int main() {
    // 测试阶乘
    int n = 10;
    std::cout << "Computing " << n << "! = ";
    std::cout << compute_factorial(n) << std::endl;
    
    // 测试深层递归
    try {
        RecursiveStack deep_stack(100 * 1024 * 1024); // 100MB 堆栈
        deep_stack.call(deep_recursion, 1000000);     // 100万层递归
        
        std::cout << "\nTesting deep recursion (1,000,000 levels)..." << std::endl;
        while (!deep_stack.done()) {
            deep_stack.execute();
        }
        std::cout << "Deep recursion completed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Deep recursion failed: " << e.what() << std::endl;
    }
    
    return 0;
}
