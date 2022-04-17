#include<stdio.h>

int main(){
    int a[5] = {1,2,3,4,5};
    int *p = (int *)(&a+1); //undefined
    int *q = (int *)(&a) + 1;

    printf("%d\n", *(a+1));
    printf("%d\n", *p-1);
    printf("%d\n", *q); // == a[1]
}
