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
    NODE *c = *h;

    while(c){
        
        /*First, set the current node to be the min NODE*/
        NODE *minNode = c;
        
        /* r is stand for the rear node */
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
    /* if the node is NULL or it is just one node */
    if( !(*h) || !((*h)->next) ) return;

    /* create the prior and the post node, which save the prior/post part of the linked list */
    NODE *prior = NULL;
    NODE *post = NULL;
    
    /* same as the middle of linked list(return the prior middle) */
    spilitLinked(h, &prior, &post);
    
    mergeSort(&prior);
    mergeSort(&post);
    
    *h = merge(prior, post);
}

/* use the recursive method */
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

/*  same as the middle of linked list(return the prior middle) */
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
    
    /* f(front) will take the original h(head) */
    *f = *h;
    
    /* p(post) will take the post part of the linked list, which starts at slow->next */
    *p = slow->next;
    
    /* cut the linked list in the middle */
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
