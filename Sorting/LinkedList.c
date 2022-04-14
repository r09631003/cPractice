#include<stdio.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

NODE *middle(NODE **);
void traverse(NODE **);
void insert(NODE **, int);
int getLength(NODE **);

void swapNode(NODE *, NODE *);
NODE* merge(NODE*, NODE*);
void selectionSortLinkedList(NODE **h);

int main(){
    NODE *h = NULL;

    insert(&h, -7);
    insert(&h, 5);
    insert(&h, 6);
    insert(&h, 4);
    insert(&h, 8);
    insert(&h, 3);
    insert(&h, 7);
    insert(&h, 5);
    insert(&h, 0);
    insert(&h, 7);
    insert(&h, 8);
    insert(&h, 10);
    insert(&h, 7);
    insert(&h, 9);
    insert(&h, 105);
    insert(&h, 300);
    insert(&h, -1);

    traverse(&h);


    selectionSortLinkedList(&h);
    traverse(&h);

    return 0;
}

void selectionSortLinkedList(NODE **h){
    int len = getLength(h);

    NODE *c = *h;

    while(c){
        NODE *minNode = c;
        NODE *r = c->next;

        while(r){
            if(r->val <= minNode->val)
                minNode = r;

            r = r->next;
        }

        swapNode(c, minNode);
        c = c->next;
    }
}

void bubbleSort(NODE **h){
    NODE *c = *h;
    int len = getLength(h);

    while(len > 0){
        int i = 0;
        NODE *d = c;

        while(i < len - 1){
            if(d && d->next && (d->next->val <= d->val)) swapNode(d, d->next);
            d = d->next;
            i++;
        }
        len--;
        c = *h;
    }
}

void mergeSort(NODE **h){
    if( !(*h) || !((*h)->next) ) return;

    NODE *prior = NULL;
    NODE *post = NULL;

    spilitLinked(h, &prior, &post);

    mergeSort(&prior);
    mergeSort(&post);
    *h = merge(prior, post);
}

NODE* merge(NODE* a, NODE* b){
    if (a == NULL) {
        return b;
    }

    else if (b == NULL) {
        return a;
    }

    NODE* result = NULL;

    if(a->val <= b->val){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void spilitLinked(NODE **h, NODE **f, NODE **p){
    if (!(*h) || !((*h)->next)){
        *f = *h;
        *p = NULL;
        return;
    }

    NODE *fast = (*h)->next;
    NODE *slow = (*h);


    while(fast){
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *f = *h;
    *p = slow->next;
    slow->next = NULL;
}

int getLength(NODE **h){
    int len = 0;
    NODE *c = *h;
    while(c){
        len++;
        c = c->next;
    }
    return len;
}

void traverse(NODE **h){
    NODE *c = *h;
    while(c){
        printf("%d ", c->val);
        c = c->next;
    }
    printf("\n");
}

void insert(NODE **h, int val){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->val = val;
    newNode->next = NULL;


    if(!(*h))
        *h = newNode;
    else{
        NODE *c = *h;

        while(c->next){
            c = c->next;
        }

        c->next = newNode;
    }
}

void swapNode(NODE *a, NODE *b){
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}
