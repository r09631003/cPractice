#include <stdio.h>
#include<stdbool.h>
#include<stdint-gcc.h>

void isMultipleof16(int);
bool is16theSame(unsigned short);

int main(){
    return 0;
}

void isMultipleof16(int n){
    printf("%d is multiple of 16: %s\n", n, (n >= 16 && !(n & 15))?"True":"False");
}

bool is16theSame(unsigned short n){
    /*use the mask to extract the last 4 digits*/
    int mask = n&15;
    int i = 0;

    /*use the mask to toggle the different digit in the given N*/
    while(i < 4){
        n = n ^ mask;
        mask <<= 4;
        i++;
    }

    return n == 0;
}
