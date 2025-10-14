#include <stdint.h>
void add_with_carry(uint64_t a, uint64_t b, 
uint64_t* result, uint64_t* carry)
{
    asm (
        "addq %[input_a], %[input_b] \n\t"
        "setc %b[output_carry]       \n\t"
        : [input_b] "+r" (b), 
          [output_carry] "=r" (*carry)
        : [input_a] "r" (a)
        : "cc"
    );
    *result = b;
}
#include <iostream>
int main() {
    uint64_t num1 = 0xFFFFFFFFFFFFFFFF;
    uint64_t num2 = 1;
    uint64_t result;
    uint64_t carry_flag;
    add_with_carry(num1, num2, &result, &carry_flag);
    std::cout << "Result: " << std::hex << result << "\n";
    std::cout << "Carry: " << carry_flag << "\n";
    return 0;
}