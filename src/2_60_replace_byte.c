#include <stdio.h>

unsigned
replace_byte(unsigned x, int index, unsigned char b);

int main(int argc, char const *argv[])
{
    int num = 0x12345678;
    printf("re1 --- %x, re2---%x\n", replace_byte(num, 2, 0xAB), replace_byte(num, 0, 0xAB));
    return 0;
}

unsigned
replace_byte(unsigned x, int index, unsigned char b){
    int mask = 0xFF << (index * 4);
    // printf("index --- %d, mask --- %x\n", index, mask);
    // printf("x & ~mask --- %x, b << (index * 4) --- %x\n", x & ~mask, b << (index * 4));
    return (x & ~mask) + (b << (index * 4));
}