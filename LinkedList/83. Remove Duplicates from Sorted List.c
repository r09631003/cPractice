#include<stdio.h>

extern struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

void traverse(NODE **);
void insert(NODE **, int);

NODE* deleteDuplicates(NODE*);

int main(){
    NODE *h = NULL;

    insert(&h, 0);
    insert(&h, 1);
    insert(&h, 1);
    insert(&h, 1);
    insert(&h, 2);
    insert(&h, 3);
    insert(&h, 3);
    insert(&h, 3);
    insert(&h, 4);

    traverse(&h);

    NODE *r = deleteDuplicates(h);

    traverse(&r);


    return 0;
}

NODE* deleteDuplicates(NODE* h){
    NODE *c = h;

    while(c && c->next){
        if(c->val != c->next->val) c = c->next;
        else{
            NODE *tmp = c->next;
            c->next = c->next->next;
            free(tmp);
        }
    }

    return h;
}


void traverse(NODE **h){
    NODE *cur = *h;
    while(cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}

void insert(NODE **h, int val){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->val = val;
    newNode->next = NULL;

    if(!(*h)){
        *h = newNode;
        return;
    }

    NODE *cur = *h;

    while(cur->next){
        cur = cur -> next;
    }

    cur->next = newNode;
}
