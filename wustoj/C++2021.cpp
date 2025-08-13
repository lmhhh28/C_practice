#include <iostream>
#include <exception>
#include <cstring>
#include <istream> // 添加头文件
using namespace std;

class CSTRING {
private:
    static const int MAX = 256;
    char *str;
    size_t lenth;
    
    void alloc() {
        str = new char[MAX](); // 初始化为零
    }
    
    void free() {
        delete[] str;
        str = nullptr;
        lenth = 0;
    }
    
public:
    // 合并构造函数
    CSTRING(const char *s = nullptr) : str(nullptr), lenth(0) {
        alloc();
        if (s) {
            lenth = std::strlen(s);
            if (lenth >= MAX) {
                free();
                throw std::runtime_error("Memory Overflow in Initing!");
            }
            std::strcpy(str, s);
        } else {
            str[0] = '\0';
        }
    }
    
    CSTRING(const CSTRING& s) : str(nullptr), lenth(s.lenth) {
        alloc();
        std::strcpy(str, s.str);
    }
    
    ~CSTRING() { 
        free(); 
    }
    
    CSTRING& operator=(const CSTRING& s) {
        if (this != &s) {
            lenth = s.lenth;
            std::strcpy(str, s.str);
        }
        return *this;
    }
    
    CSTRING& operator+=(const CSTRING& s) {
        size_t newLen = lenth + s.lenth;
        if (newLen >= MAX) {
            throw std::runtime_error("Memory Overflow in SelfAdding!");
        }
        std::strcat(str, s.str); // 使用strcat而非strcpy
        lenth = newLen;
        return *this;
    }
    
    friend CSTRING operator+(const CSTRING&, const CSTRING&);
    friend std::ostream& operator<<(std::ostream&, const CSTRING&);
    friend std::istream& operator>>(std::istream&, CSTRING&); // 修改为非const
};

CSTRING operator+(const CSTRING& s1, const CSTRING& s2) {
    CSTRING temp = s1;
    temp += s2;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const CSTRING& s) {
    os << (s.str ? s.str : "");
    return os;
}

// 修复输入运算符
std::istream& operator>>(std::istream& in, CSTRING& s) {
    char buffer[CSTRING::MAX];
    if (in >> buffer) {
        size_t len = std::strlen(buffer);
        if (len >= CSTRING::MAX - 1) {
            in.setstate(std::ios::failbit);
            throw std::runtime_error("Input too long");
        }
        std::strcpy(s.str, buffer);
        s.lenth = len;
    }
    return in;
}

int main() {
    try {
        CSTRING s1("Hello");
        CSTRING s2 = "World!";
        s1 += s2;
        std::cout << s1 << std::endl; // 应输出 "HelloWorld!"
        
        CSTRING s4 = s2;
        std::cout << s4 << std::endl; // 应输出 "World!"
        
        // 测试加法运算符
        CSTRING s3 = s1 + "!";
        std::cout << s3 << std::endl; // 应输出 "HelloWorld!!"
        
        // 测试输入
        CSTRING input;
        std::cout << "Enter a CSTRING: ";
        std::cin >> input;
        std::cout << "You entered: " << input << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
