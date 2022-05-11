#include<stdio.h>

/* Leetcode 136. Single Number */
int singleNumber(int* nums, int numsSize){
    int tmp = nums[0];

    for(int i = 1; i < numsSize; i++){
        tmp ^= nums[i];
    }

    return tmp;
}

/* Leetcode Single Number III */

void singleNumberIII(int *nums, int numsSize){
    int tmp = nums[0];
    int ans[2];

    ans[0] = 0;
    ans[1] = 0;

    /* XOR all the number in array. will get the number represents the diff between the 2 unique number */
    for(int i = 1; i < numsSize; i++){
        tmp ^= nums[i];
    }

    /* The mask will find the last 1. in tmp, and the 1. represent the last different bits in the two unique number */
    tmp &= (-tmp);


    /* Divide the nums into 2 part: has / has no same bit with mask */
    for(int i = 0; i < numsSize; i++){
        if(nums[i] & tmp)        /* If nums & mask == 0, it means that it has no same bit with mask */
            ans[0] ^= nums[i];
        else
            ans[1] ^= nums[i];
    }

    printf("%d %d\n", ans[0], ans[1]);

}

int main(){
    int n[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,81,4742};
    int len = sizeof(n) / sizeof(n[0]);

    //int ans = singleNumber(n, len);
    singleNumberIII(n, len);
    //printf("%d", ans);

}
