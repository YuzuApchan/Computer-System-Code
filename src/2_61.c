#include <stdio.h>
#include <math.h>
#include <limits.h>

int isEveryBitEqualOne(int num)
{
    return num == INT_MIN;
}
int isEveryBitEqualZero(int num)
{
    return num == 0;
}
int isLastSignificantBitEqualOne(int num)
{
    return num & 0xFF == 0xFF;
}
int isMostSignificantBitEqualZero(int num)
{
    return num & ~0xFF == 0x00;
}
int int_shifts_are_arithmetic()
{
    return (-1 >> 1) < 0;
}

/*-----------------------------2.63 start-----------------------------*/
/* a by l*/
unsigned srl(unsigned x, int k){
    unsigned xsra = (int)x >> k;        
    // 高位有意料之外的 k个0，改成1
    int mask = pow(2, k) - 1;
    return xsra & ~(mask >> (8 * sizeof(int) - k));
}

/* l by a*/
unsigned sra(int x, int k){
    int xsrl = (unsigned)x >> k;
    int mask = pow(2, k) - 1;
    return xsrl | (mask >> (8 * sizeof(int) - k));
}

/*-----------------------------2.64 start-----------------------------*/
int any_old_one(unsigned x){
    int mask = 0x5555; // 0101 0101 0101 0101
    return x & mask;
}

/*-----------------------------2.65 start-----------------------------*/
/* 位图中 1 的个数，因此计数时类似异或（模二加） ^ */
int odd_ones(unsigned x){
    unsigned result1 = (x >> 16) & (x & 0xFFFF);
    unsigned result2 = (result1 >> 8) & (result1 & 0xFF);
    unsigned result3 = (result2 >> 4) & (result2 & 0xF);
    unsigned result4 = (result3 >> 2) & (result3 & 0x3);
    return result4 >> 1 & result4 & 0x1;
}

/*-----------------------------2.66 start-----------------------------*/
int leftmost_one(unsigned x){

    
}

int main(int argc, char const *argv[])
{
    printf("---------2.62---------\n");
    printf("int_shifts_are_arithmetic --- %d\n", int_shifts_are_arithmetic());

    printf("---------2.63---------\n");
    unsigned ux = 10;
    int x = 10;
    int k = 2;
    printf("a by l: %d\n", srl(ux, k));
    printf("l by a: %d\n", sra(x, k));

    return 0;
}
  