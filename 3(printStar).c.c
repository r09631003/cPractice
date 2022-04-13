#include<stdio.h>

void printTriangle(int const);
void printPyramid(int const);
void printDiamod(int const);

int main(){
    int n = 5;

    printPyramidII(n);

    return 0;
}

void printTriangle(int const n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void printPyramid(int const n){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            printf(" ");
        }

        for(int k = 0; k < i + 1; k++){
            printf("* ");
        }

        printf("\n");
    }
    printf("\n");
}

void printDiamod(int const n){
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            printf(" ");
        }

        for(int k = 0; k < i + 1; k++){
            printf("* ");
        }

        printf("\n");
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            printf(" ");
        }

        for(int k = n - 1; k > i; k--){
            printf("* ");
        }

        printf("\n");
    }
    printf("\n");
}
