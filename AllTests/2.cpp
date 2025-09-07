#include <stdint.h> // 用于 uint64_t
void add_with_carry(uint64_t a, uint64_t b, uint64_t* result, int* carry) {
    // 扩展内联汇编语法
    asm (
        "addq %[input_a], %[input_b] \n\t"  // 执行加法: input_b = input_b + input_a
        "setc %b[output_carry]       \n\t"  // 根据 CF 设置 output_carry (8位寄存器)

        // 输出操作数列表
        : [input_b] "+r" (b),        // 输入输出操作数：使用寄存器，初始值为b，结果也写回这里
          [output_carry] "=r" (*carry) // 输出操作数：将结果写入carry指向的内存

        // 输入操作数列表
        : [input_a] "r" (a)          // 输入操作数：使用寄存器，值为a

        // Clobber 列表：显式告诉编译器我们修改了 EFLAGS 寄存器
        : "cc"
    );

    *result = b; // 加法结果已经在变量 b 中
}

// 使用示例
#include <iostream>
int main() {
    uint64_t num1 = 0xFFFFFFFFFFFFFFFF; // 最大值
    uint64_t num2 = 1;
    uint64_t result;
    int carry_flag;

    add_with_carry(num1, num2, &result, &carry_flag);

    std::cout << "Result: " << std::hex << result << "\n";
    std::cout << "Carry: " << carry_flag << "\n";
    // 输出应为:
    // Result: 0
    // Carry: 1
    return 0;
}
