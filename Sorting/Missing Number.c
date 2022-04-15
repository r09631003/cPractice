#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int SIZE = 99;

/* Use the Pyramid Method */
void theLostNumber(int *arr){
    int total = 0;

    for(int i = 0; i < SIZE; i++)
        total += arr[i];



    printf("\n%d\n", ((1+100)*100 / 2)-total);
}

void theLostNumberInSortingArray(int *arr){
    return;
}

int main(){
    srand(time(NULL));
    int arr[SIZE];

    int lostNumber =  1 + (rand() % 100);
    int i = 0;
    int j = 1;

    printf("%d\n", lostNumber);

    while(i < SIZE){
        if(j == lostNumber){
            j++;
            continue;
        }

        arr[i] = j;
        i++;
        j++;
    }

    theLostNumber(arr);
}
