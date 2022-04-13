#include<stdio.h>
#include<stdbool.h>

void selectionSort(int *, int);
void bubbleSort(int *, int);
void insertSort(int *, int);
void quickSort(int *, int, int);
void mergesort(int *, int, int, bool *(cmp)(int, int));
void merge(int *, int, int, int, bool *(cmp)(int, int));
int findPivot(int *, int, int);
void swap(int *, int *);
bool isGreater(int, int);
bool isSmaller(int, int);
bool (*cmp)(int, int);

int main(){
    int arr[] = {1,0,5,8,9,3,5,4,6,2,1,0,8,6,41,25,6,3,0,4,8,9,6};
    int len = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr, 0, len-1, isSmaller);

    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

bool isGreater(int a, int b){
    return a >= b;
}

bool isSmaller(int a, int b){
    return a < b;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void mergesort(int *arr, int l, int r, bool *(cmp)(int, int)){
    if(l < r){
        int mid = l + (r - l) / 2;

        mergesort(arr, l, mid, cmp);

        mergesort(arr, mid+1, r, cmp);

        merge(arr, l, mid, r, cmp);
    }
}

void merge(int *arr, int l, int mid, int r, bool *(cmp)(int, int)){
    int left[mid - l + 1];
    int right[r - mid];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < mid - l + 1)
        left[i++] = arr[k++];

    while(j < r - mid)
        right[j++] = arr[k++];

    i = 0;
    j = 0;
    k = l;

    while(i < mid - l + 1 && j < r - mid){
        if(cmp(left[i], right[j]))
            arr[k] = right[j++];

        else
            arr[k] = left[i++];

        k++;
    }

    while(j < r - mid)
        arr[k++] = right[j++];

    while(i < mid - l + 1)
        arr[k++] = left[i++];

}

void quickSort(int *arr, int l, int r){
    if(l < r){

        int pivot = findPivot(arr, l, r);

        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int findPivot(int *arr, int l, int r){
    int pivot = l;
    int i = pivot;
    int j = r;

    while(i < j){
        while(arr[i] <= arr[pivot]){
            i++;
        }

        while(arr[j] > arr[pivot]){
            j--;
        }

        if(i < j) swap(&arr[i], &arr[j]);
    }

    swap(&arr[pivot], &arr[j]);

    return j;
}

void selectionSort(int * arr, int len){
    for(int i = 0; i < len; i++){
        int min = i;
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        swap(&arr[min], &arr[i]);
    }
}

void bubbleSort(int * arr, int len){

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertSort(int * arr, int len){
    for(int i = 0; i < len; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}
