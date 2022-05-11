#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<stdint-gcc.h>
#define setBit1(N, n) ((N)|=(1<<(n)))

/* Naive Method */
void findHighestBit(unsigned int n){
    int x = 31;
    uint32_t mask = 1 << 31;

    while(mask > 0){
        if(n & mask) break;
        mask >>= 1;
    }
    
    printf("The highest bit is %d\n", mask);
}


/* Better method */
void findHighestBitII(unsigned int n){
    /*set the highest bit(and the lower bits) to 1 */
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    /* ex: 111 - 11; we can get 100, which is the highest bit of 111 */
    printf("%ud\n", n - (n >> 1));
}

/* Lowest order of bit */
void findLowestBit(unsigned int n){
    /* -n: is the 2 complement of n */
    /* n & (-n) can get the lowest bit(right most bit) */
    int tmp = n & (-n);

    printf("%d\n", tmp);
}

int main(){
    findLowestBit(8720);

    return 0;
}
