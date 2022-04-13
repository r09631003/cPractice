#include<stdio.h>
#include <stdint.h>

/*ceiling to 32:*/
/*if 31-> 32*/
/*if 32-> 32*/
/*if 67-> 96*/
/*if 154-> 160*/

int ceiling32(int n){
    return ((((n - 1)>>5)+1)<<5);
}

/*Naive Method*/
int ceiling32II(int n){
    int i = 1;
    int ans = 0;

    while(i * 32 <= UINT32_MAX){
        if(n > 32*i){
            i++;
        }

        else{
            ans = i * 32;
            break;
        }
    }
    return ans;
}

int main(){

    int n = 154;

    int c = ceiling32II(n);

    printf("After ceiling: %d\n", c);

    return 0;
}
