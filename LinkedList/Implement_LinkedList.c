#include<stdio.h>
#include<stdbool.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

/* Tool */
void traverse(NODE **);
bool isEmpty(NODE **);
NODE *search(NODE **, int);

/* Delete node */
void pushBack(NODE **, int);
void pushFront(NODE **, int);
void insertNodeByPos(NODE **, int); /*Insert by Given Address*/
void insertNodeBySequence(NODE **, int, int); /*Insert by Nst*/

/* Insert node */
void popBack(NODE **);
void popFront(NODE **);
void deleteNodeByPos(NODE **); /*Delete by Given Address*/
void deleteNodeBySequence(NODE **, int); /*Delete by Nst*/

/* Create linked list by given array */
void create(NODE **, int *, int);


int main(){
    NODE *h = NULL;

    pushBack(&h, 2);
    pushBack(&h, 4);
    pushBack(&h, 3);
    pushBack(&h, 6);

    insertNodeBySequence(&h, 1, 1);
    traverse(&h);
}

void create(NODE **head, int *arr, int len){
    NODE *prev;

    for(int i = 0; i < len; i++){
        NODE *cur = (NODE *)malloc(sizeof(NODE));
        cur->val = arr[i];

        if(i == 0)
            *head = cur;
        else
            prev->next = cur;

        cur->next = NULL;
        prev = cur;
    }
}

void insertNodeBySequence(NODE **h, int N, int x){
    if(N == 1) pushFront(h, x);
    else{
        NODE *c = *h;

        N = N - 2;                      /* The pointer should stand on the n-1 node */

        while(c && N > 0){
            c = c->next;
            N--;
        }

        if(!c) return;                  /* Add on the 1 ~ Length + 1, if the N is greater to (Length + 1), then return */

        NODE *n = (NODE *)malloc(sizeof(NODE));
        n->val = x;
        n->next = NULL;

        NODE *tmp = c->next;
        c->next = n;
        c->next->next = tmp;
    }
}

void deleteNodeBySequence(NODE **h, int N){
    if(isEmpty(h)) return;

    if(N == 1) popFront(h);
    else{
        NODE *c = *h;

        N = N - 2;                      /* The pointer should stand on the n-1 node */

        while(c && N > 0){
            c = c->next;
            N--;
        }

        if(!c || !(c->next)) return;        /* Add on the 1 ~ Length, if the N is greater to (Length), then return */

        NODE *tmp = c->next;
        c->next = c->next->next;
        free(tmp);

    }
}

bool isEmpty(NODE **h){
    return (!(*h));
}

void deleteNodeByPos(NODE **p){
    if(isEmpty(p)) return;

    (*p)->val = (*p)->next->val;
    NODE *n = (*p)->next->next;
    NODE *tmp = (*p)->next;

    (*p)->next = n;
    free(tmp);
}

void popFront(NODE **h){
    if(isEmpty(h)) return;

    NODE *tmp = *h;
    (*h) = (*h)->next;
    free(tmp);
}

void popBack(NODE **h){
    if(isEmpty(h)) return;
    NODE *c = *h;

    while(c->next->next){
        c = c->next;
    }

    NODE *tmp = c->next;
    c->next = NULL;
    free(tmp);
}

NODE *search(NODE **h, int x){
    if(isEmpty(h)) return NULL;
    NODE *c = *h;

    while(c){
        if(c->val == x) return c;
        c = c->next;
    }

    return NULL;
}

void traverse(NODE **h){
    if(isEmpty(h)) return;
    NODE *c = *h;

    while(c){
        printf("%d ", c->val);
        c = c->next;
    }

    printf("\n");
}



void insertNodeByPos(NODE **p, int x){
    if(isEmpty(p)) return;

    NODE *n = (NODE *)malloc(sizeof(NODE));

    n->val = (*p)->val;
    (*p)->val = x;
    NODE *tmp = (*p)->next;
    (*p)->next = n;
    (*p)->next->next = tmp;

    return;
}

void pushFront(NODE **h, int x){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->val = x;
    n->next = NULL;

    if(isEmpty(h))
        *h = n;
    else{
        n->next = *h;
        *h = n;
    }
}

void pushBack(NODE **h, int x){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->val = x;
    n->next = NULL;

    if(isEmpty(h))
        *h = n;
    else{
        NODE *c = *h;
        while(c->next)
            c = c->next;
        c->next = n;
    }
}
