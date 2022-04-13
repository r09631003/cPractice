#include <stdio.h>
#include<stdbool.h>
#include<stdint-gcc.h>

void isMultipleof16(int);
bool is16theSame(unsigned short);

int main(){
    return 0;
}

/*N is Multiplied by 16*/
void isMultipleof16(int n){
    printf("%d is multiple of 16: %s\n", n, (n >= 16 && !(n & 15))?"True":"False");
}

/*給你一個unsigned short(0~65535)，問換算成16進制後四個值是不是一樣，是回傳1，否則0。例如：0xFFFF return 1, 0xAAAB return 0*/
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
