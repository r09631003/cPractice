#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define cards_size 52

void shuffle(int *array, int n){
    /* Important! The random seed will be fixed. Set time NULL can get different seed */
    srand(time(NULL));

    if (n > 1){
        for (int i = 0; i < n; i++){
            int swap_idx = rand() % n;   /* set the randint to the range in 0~52 */

            /* the code below is for swap */
            int tmp = array[i];
            array[i] = array[swap_idx];
            array[swap_idx] = tmp;
        }
    }
}

int main(){

    int given[cards_size];

    for(int i = 0; i < cards_size; i++){
        given[i] = i + 1;
    }

    for(int i = 0; i < cards_size; i++){
        printf("%d ", given[i]);
    }

    printf("\n\n\n");

    shuffle(given, cards_size);

    for(int i = 0; i < cards_size; i++){
        printf("%d ", given[i]);
    }


}
