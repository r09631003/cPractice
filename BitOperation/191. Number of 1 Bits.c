#include<stdio.h>

void howManyOneinBinary(int n){
    /*Naive method*/
    int cnt = 0;

    while(n > 0){
        if(n & 1) cnt++;
        n >>= 1;
    }

    printf("%d\n", cnt);
}

void howManyOneinBinaryII(int n){
    /*Brian Kernighan¡¦s algorithm*/
    int ans = 0;

    while(n > 0){
        n = n & (n-1);
        ans++;
    }

    printf("\nThere are %d of 1s in %d\n", ans, n);
}

int main(){
    return 0;
}
