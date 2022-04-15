/*¸sÁp3ÃD-1*/
#include<stdio.h>

void phisonFitst(int *, int);
void phisonSecond(int *, int, int);


int main(){

}

void phisonFitst(int *arr, int len){
    for(int i = 0; i <= 500; i++){
        if(i == *(arr))
            arr++;
        else
            printf("%d ", i);
    }
    printf("\n");
}

void phisonSecond(int *arr, int len, int b){
    while(*arr < b * 100)
        arr++;

    for(int i = b * 100; i < (b+1)*100; i++){
        if(*(arr) == i)
            arr++;

        else
            printf("%d ", i);

    }
    printf("\n");
}

