#include<stdio.h>
#include<stdbool.h>
#define setBit(N, s) ((N)|=(1<<(s)))
#define clearBit(N, s) ((N)&=~(1<<(s)))
#define toggleBit(N, s) ((N)^=(1<<(s)))

bool isNegative(int);
void isPowerOf2(int);
void abs(int);
void isOdd(int);

int main(){
    isOdd(169370);
}

void isOdd(int n){
    printf("%s\n", (n & 1)?"True":"False");
}

bool isNegative(int n){
    return n & (1 << 31);
}

void isPowerOf2(int n){
    printf("%s\n", (n > 0 && !(n & (n-1)))?"True":"False");
}

void abs(int n){
    if(n > 0) return;


    /*~ operator can toggle all the bits in n*/
    /*if n == 5*/
    /* n = 00000000000000000000000000000101*/
    /* ~n = 11111111111111111111111111111010*/
    /* ~n+1 = 11111111111111111111111111111011*/

    /*(~n)+1 will multiple -1 to n*/

    printf("ABS(%d) = %d\n", n, (~n)+1);
}

void abs(int n){
    /* Notice that if all the negative number (32th == 1) right shift 32 will always be -1 */
    /* Remember it!!! */
    /* (n >> 31) ^ n equals to the 1's complement operation */
    /* -(n >> 31) equals to the 2's complement operation */
    
    return ((n >> 31) ^ n) - (n >> 31));
}

