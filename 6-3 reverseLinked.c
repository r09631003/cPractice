#include<stdio.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

void print(NODE **);
void insert(NODE **, int);
NODE *reverse(NODE **);

int main(){
    NODE *h = NULL;

    insert(&h, 1);
    insert(&h, 2);
    insert(&h, 3);
    insert(&h, 4);
    insert(&h, 5);
    print(&h);
    NODE *r = reverse(&h);
    print(&r);
}

NODE *reverse(NODE **h){
    NODE *r = NULL;

    while(*h){
        NODE *tmp = *h;
        *h = (*h)->next;
        tmp->next = r;
        r = tmp;
    }

    return r;
}

void insert(NODE **h, int x){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->val = x;
    n->next = NULL;

    if(!(*h))
        *h = n;
    else{
        NODE *c = *h;
        while(c->next)
            c = c->next;
        c->next = n;
    }
}

void print(NODE **h){
    if(!(*h)) return;
    NODE *cur = *h;
    while(cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}


