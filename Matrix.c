#include<stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void transposeInPlace(int n, int arr[n][n]){
    /* Notice: the pointer for column (j) should go from back to front */
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= i; j--){
            swap(&arr[i][j], &arr[j][i]);
        }
    }

    return;
}

void transposeExtraPlace(int n, int arr[n][n]){
    int to[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            to[j][i] = arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", to[i][j]);
        }

        printf("\n");
    }
}

void multipleMatrix(int r1, int c1, int a[r1][c1], int r2, int c2, int b[r2][c2]){
    if(c1 != r2) return;
    int res[r1][c2];

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            int tmp = 0;
            for(int k = 0; k < c1; k++)
                tmp += (a[i][k]*b[k][j]);
            res[i][j] = tmp;
        }
    }

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int r1 = 3;
    int c1 = 3;
    int arr1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int r2 = 3;
    int c2 = 4;
    int arr2[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    multipleMatrix(r1, c1, arr1, r2, c2, arr2);



    return 0;
}
