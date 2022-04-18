#include<stdio.h>

/* The divisor should be the power of 2 */
int remainder(int dividend, int divisor){
    return dividend & (divisor - 1);
}

/* For example: 29 can be represent by 11101 */
/* if we want to divide 29 by 4 we just need to right shift 29 by 2 */
/* as the result, the remainder will be the right most 2 bits */
/* if divide by 8, the remainder will be the right most 3 bits */

/* so we just need to extract the right most bit */
/* we should use the n - 1 as the mask to do the AND operation with n */

int main(){
    int divisor = 16;
    int dividend = 29;

    int ans = remainder(dividend, divisor);
    printf("Ans = %d\n", ans);

    return 0;
}
