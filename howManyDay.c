#include<stdio.h>
#include<stdbool.h>


bool isLeapYear(int);
void isLeap(int , int *);
void dateAfterXday(int *, int *, int *, int);
void cntDayDifference(int *, int *, int *, int *, int *, int *, int *);

int main(){
    int year1, month1, day1;
    int year2, month2, day2;

    printf("請輸入日期1:");
    scanf("%d-%d-%d", &year1, &month1, &day1);

    printf("\n請輸入日期2:");
    scanf("%d-%d-%d", &year2, &month2, &day2);

    int diff = 0;
    cntDayDifference(&year1, &month1, &day1, &year2, &month2, &day2, &diff);

    printf("天數差異: %d\n", diff);

    return 0;
}

void cntDayDifference(int *y1, int *m1, int *d1, int *y2, int *m2, int *d2, int *diff){
    int month_date[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int sum1 = 0;
    int sum2 = 0;

    int y = *y1;
    int m = 1;


    for(m = 1; m < *m1; m++){
        if(m == 2) isLeap(*y1, &month_date[1]);
        sum1 += month_date[m-1];
    }

    sum1 += *d1;


    for(y = y; y < *y2; y++){
        sum2 += isLeapYear(y)?366:365;
    }

    for(m = 1; m < *m2; m++){
        if(m == 2) isLeap(*y2, &month_date[1]);
        sum2 += month_date[m-1];
    }

    sum2 += *d2;


    *diff = sum2 - sum1 + 1;
}

void dateAfterXday(int *y, int *m, int *d, int x){
    int month_date[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int sum = x + *d;

    while(sum > month_date[(*m)-1]){
        if((*m) == 2)
            isLeap(*y, &month_date[(*m)-1]);

        if(sum > month_date[(*m)-1]){
            sum -= month_date[(*m)-1];
            (*m)++;
            if((*m) == 13){
                (*y)++;
                (*m) = 1;
            }
        }
    }

    *d = sum;
}

void isLeap(int y, int *daysOfFeb){
    if(y % 4 == 0){
        if(y % 400 == 0)
            *daysOfFeb = 29;

        else if(y % 100 == 0 && y % 400 != 0)
            *daysOfFeb = 28;

        *daysOfFeb = 29;
    }

    else
        *daysOfFeb = 28;
}

bool isLeapYear(int y){
    if(y % 4 == 0){
        if(y % 400 == 0)
            return true;

        else if(y % 100 == 0 && y % 400 != 0)
            return false;

        return true;
    }

    else
        return false;
}


