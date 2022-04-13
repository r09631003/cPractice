#include<stdio.h>

int binarySearch(int *, int, int);
int rootInt(int);
float rootFloat(int);
float rootFloatII(int);

int main(){

    int arr[] = {1,2,5,8,9,12,15,16,19,25,29,31,38,39,40,45,49,54,58,75,99,101,102,106};
    int len = sizeof(arr)/sizeof(arr[0]);

    int idx = binarySearchII(arr, len, 120);
    printf("the index / the nearest idx: %d\n", idx);

    return 0;
}

int binarySearch(int *arr, int len, int target){
    int l = 0;
    int r = len - 1;

    while(l <= r){

        int mid = l + (r - l)/2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int binarySearchII(int *arr, int len, int target){
    int l = 0;
    int r = len - 1;

    while(l <= r){

        int mid = l + (r - l)/2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l-1;
}

int rootInt(int n){
    int l = 1;
    int r = n;

    while(l <= r){
        int mid = l + (r - l)/2;

        if(mid * mid == n)
            return mid;
        else if(mid * mid < n)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return l - 1;
}

float rootFloat(int n){
    int l = 10;
    int r = n * 10;

    while(l <= r){

        int mid = l + (r - l)/2;

        if(mid * mid == (n*10*10))
            return mid / 10;
        else if(mid * mid < (n*10*10))
            l = mid + 1;
        else
            r = mid - 1;
    }

    return (float)(l-1)/10;
}

float rootFloatII(int n){
    int l = 100;
    int r = n * 100;

    while(l <= r){

        int mid = l + (r - l)/2;

        if(mid * mid == (n*100*100))
            return mid / 100;
        else if(mid * mid < (n*100*100))
            l = mid + 1;
        else
            r = mid - 1;
    }

    return (float)(l-1)/100;
}

