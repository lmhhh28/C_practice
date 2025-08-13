#include<iostream>

static  std::size_t __val_0 = 1;
        std::size_t __val_1 = 2;

int main(void) {
    std::size_t __val_2 = 3;
    
    std::size_t&    __ref_0 = __val_0;
    std::size_t&    __ref_1 = __val_1;
    std::size_t&    __ref_2 = __val_2;
    
    void* __p_1 = __builtin_addressof(__ref_0);
    void* __p_2 = __builtin_addressof(__ref_1);
    void* __p_3 = __builtin_addressof(__ref_2);
    
    std::cout << "0x" << __p_1 << std::endl;
    std::cout << "0x" << __p_2 << std::endl;
    std::cout << "0x" << __p_3 << std::endl;
}

