#include<stdio.h>
#include<stdbool.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

/*tool*/
void traverse(NODE **);
bool isEmpty(NODE **);
NODE *search(NODE **, int);

/*delete node*/
void pushBack(NODE **, int);
void pushFront(NODE **, int);
void insertNodeByPos(NODE **, int); /*Insert by Given Address*/
void insertNodeBySequence(NODE **, int, int); /*Insert by Nst*/

/*insert node*/
void popBack(NODE **);
void popFront(NODE **);
void deleteNodeByPos(NODE **); /*Delete by Given Address*/
void deleteNodeBySequence(NODE **, int); /*Delete by Nst*/


int main(){
    NODE *h = NULL;

    pushBack(&h, 2);
    pushBack(&h, 4);
    pushBack(&h, 3);
    pushBack(&h, 6);

    insertNodeBySequence(&h, 1, 1);


    traverse(&h);
}

void insertNodeBySequence(NODE **h, int N, int x){
    if(N == 1) pushFront(h, x);
    else{
        NODE *c = *h;

        N = N - 2; /*go to the N-1 position*/

        while(c && N > 0){
            c = c->next;
            N--;
        }

        if(!c) return;

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

        N = N - 2; /*the pointer should stand on the n-1 node*/

        while(c && N > 0){
            c = c->next;
            N--;
        }

        if(!c || !(c->next)) return;

        printf("%d\n", c->val);

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
