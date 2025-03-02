#include <iostream>
#include <windows.h>

template <int N>
struct Fibonacci {
    static constexpr long long value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0> {
    static constexpr long long value = 0;
};

template <>
struct Fibonacci<1> {
    static constexpr long long value = 1;
};

int main() {
    DWORD start_time = GetTickCount();
    std::cout << Fibonacci<92>::value << std::endl;
    DWORD end_time = GetTickCount();
    std::cout << (end_time - start_time) << "ms." << std::endl;
    system("pause");
}
