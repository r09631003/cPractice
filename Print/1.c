#include<stdio.h>

int c;

int func(int m, int *n){
    c += 1;
    m += c;
    *n += m;
    return m;
}

int main(){
    c = 0;
    int x = 5;
    int y = 7;
    int z;
    x = func(x, &y);
    z = func(x, &y);
    printf("%d\n", x + y + z + c);
    return 0;
}
