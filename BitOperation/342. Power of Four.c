#include<stdio.h>
#include<stdbool.h>

bool isPowerof4(int);
bool isPowerof4II(int);

int main(){
    printf("%d\n", isPowerof4II(20));
}

/* Naive Method */
bool isPowerof4II(int n){
    if(n <= 0) return false;

    int i = 0;

    while(i < 31){
        if((i % 2)==0 && (n & (1<<i))){
            if((n ^ (1<<i)) == 0) return true;
            else return false;
        }
        i++;
    }

    return false;
}

/* Tricky. Power of 4 must be power of 2 and (n-1) multiple of 3 */
bool isPowerof4(int n){
    return n > 0 && !(n & (n - 1)) && (n-1)%3==0;
}
