#include<stdio.h>
#include<stdbool.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node Stack;

bool isEmpty(Stack *);
void traverse(Stack **);
void pushBack(Stack **, int);
int top(Stack **);
void popBack(Stack **);

int main(){
    Stack *s = NULL;
    bool ans = isEmpty(s);

    pushBack(&s, 5);
    pushBack(&s, 3);
    pushBack(&s, 4);

    traverse(&s);

    popBack(&s);

    traverse(&s);

    return 0;
}

void popBack(Stack **s){
    if(isEmpty(*s)) return;
    Stack *tmp = *s;
    *s = (*s)->next;
    free(tmp);
}

bool isEmpty(Stack *s){
    return !s;
}

void pushBack(Stack **s, int val){
    Stack *cur = (Stack *)malloc(sizeof(Stack));
    cur->val = val;
    cur->next = NULL;

    cur->next = *s;
    *s = cur;
}

void traverse(Stack **s){
    Stack *cur = *s;

    while(cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}

int top(Stack **s){
    if(isEmpty(*s)) return -1;

    return (*s)->val;
}

