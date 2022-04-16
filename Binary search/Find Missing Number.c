#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int SIZE = 99;

/* Unsorted Array by using math */
void theLostNumber(int *arr){
    int total = 0;

    for(int i = 0; i < SIZE; i++)
        total += arr[i];



    printf("\n%d\n", ((1+100)*100 / 2)-total);
}

/* Unsorted Array by using XOR */
/* The method is similar to the Unique Number */
/* Use the mask that XOR all the number from 1 ~ 100 */
/* Then XOR all the number with the given array and it will delete the double number */
void theLostNumberII(int *arr){
    int mask1 = 1;

    for(int i = 2; i <= 100; i++){
        mask1 ^= i;
    }

    for(int i = 1; i < SIZE; i++){
        arr[i] ^= arr[i-1];
    }

    printf("The Lost number is %d\n", arr[98] ^ mask1);
}

/* Sorted array by using Binary Search */
/* Notice !!! The boundary is quite different */

int findMissing(int arr[], int N){
	int left = 0, right = N - 1;
	while (left <= right) {

		int mid = (left + right) / 2;

		// If the middle element is not on
		// the middle index, then the missing element is mid + 1.
		if (arr[mid] != mid + 1 && arr[mid - 1] == mid){
            return mid + 1;
        }

		// This case means that the missing element is
		// not to the left. So search the right.
		if (arr[mid] == mid + 1)
			left = mid + 1;

		// This case means that the missing element is not
		// to the right. So search the left.
		else
			right = mid - 1;
	}

	// Will reach here if no missing element found.
	return -1;
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

    theLostNumberII(arr);
    //printf("%d\n", pos);
}
