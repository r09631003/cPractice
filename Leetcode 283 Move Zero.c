#include<stdio.h>



/* The problem is similar to the Leetcode. 283 Question*/
/* Move the 0 to the post part of the array */
/* Regardless the sequence of the other numbers */

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZero(int *arr, int len){
    int i = 0;
    int j = len - 1;

    while(i < j){
        while(arr[i] != 0)
            i++;
        while(arr[j] == 0)
            j--;
        if(i < j) swap(&arr[i], &arr[j]);
    }
}

int main(){
    int arr[] = {0,1,4,0,2,0,5,7,0,0,0,0,0,0,0,8,9,6,3,4,10,0,0,15,0};
    int len = sizeof(arr)/sizeof(arr[0]);

    moveZero(arr, len);


    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}
