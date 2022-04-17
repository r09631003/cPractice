#include<stdio.h>
#define ADD(a, b) a+b

void func1(){
    int m = 5, n = 10;
    int p = ADD(m, n) * 5;
    printf("%d\n", p);
}

int main(){
    func1();
    return 0;
}
