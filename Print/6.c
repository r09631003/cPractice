#include<stdio.h>

void func1(){
    char *s = "hello";
    char s1[] = {'h','e','l','l','o'};
    int s2[] = {'h','e','l','l','o'};
    char s3[] = "hello";


    printf("%d\n", sizeof(s));  /* s itself is a char pointer */
    printf("%d\n", sizeof(*s)); /* Notice!! The pointer is point to a char */
    printf("%d\n", sizeof(s1));
    printf("%d\n", sizeof(s2));
    printf("%d\n", sizeof(s3)); /* s3 is a string */
}

void func2(){
    char str1 = "hello";
    char str2[] = "hello";
    char *p1 = str1;
    char *p2 = str2;
    int n = 10;
    int a2[3];

    printf("str1: %d\n", sizeof(str1));
    printf("str2: %d\n", sizeof(str2));

    printf("p1: %d\n", sizeof(p1));
    printf("p2: %d\n", sizeof(p2));

    printf("*p1: %d\n", sizeof(*p1));
    printf("*p2: %d\n", sizeof(*p2));

    printf("n: %d\n", n);
    printf("a2: %d\n", a2);
}

struct AA{
    char a[15];
    double b;
};

int main(){
    struct AA A;
    printf("%d\n", sizeof(A));
}
