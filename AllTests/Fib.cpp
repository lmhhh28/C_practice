#include <iostream>
#include <windows.h>
typedef long long ll;

ll fib(ll num) {
    return (num == 1 || num == 2) ? 1 : fib(num - 1) + fib(num - 2);
}

int main() {
    DWORD start_time = GetTickCount();
    std::cout << fib(40) << std::endl;
    DWORD end_time = GetTickCount();
    std::cout << (end_time - start_time) << "ms." << std::endl;
}