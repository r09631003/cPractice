#include<stdio.h>

int c;

int func(int n){
    c *= n;
    return n;
}

int main(){
    c = 1;
    int n = 2;
    func(func(func(func(func(func(func(func(n))))))));

    printf("%d\n",c);
    return 0;
}
