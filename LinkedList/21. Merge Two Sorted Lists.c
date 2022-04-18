#include<stdio.h>
#include<stdbool.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

void insertBack(NODE **, int);
void traverse(NODE **);

NODE *mergeTwoSortedLinked(NODE *, NODE *);
NODE *mergeTwoLinkedByReccursion(NODE *h1, NODE *h2)

int main(){
    NODE *h1 = NULL;

    insertBack(&h1, 4);
    insertBack(&h1, 5);
    insertBack(&h1, 6);
    insertBack(&h1, 7);
    insertBack(&h1, 8);
    insertBack(&h1, 20);
    insertBack(&h1, 25);

    traverse(&h1);

    NODE *h2 = NULL;

    insertBack(&h2, 0);
    insertBack(&h2, 3);
    insertBack(&h2, 7);
    insertBack(&h2, 10);
    insertBack(&h2, 15);
    insertBack(&h2, 19);

    traverse(&h2);

    NODE *res = mergeTwoSortedLinked(h1, h2);
    traverse(&res);

    return 0;
}

/* By recurrsion method. */
NODE *mergeTwoLinkedByReccursion(NODE *h1, NODE *h2){
    if(!h1) return h2;
    else if(!h2) return h1;

    NODE *res = NULL;

    if(h1->val <= h2->val){
        res = h1;
        res->next = mergeTwoLinkedByReccursion(h1->next, h2);
    }

    else{
        res = h2;
        res->next = mergeTwoLinkedByReccursion(h1, h2->next);
    }
}

/* By while loop(traverse) method. */
NODE *mergeTwoSortedLinked(NODE *list1, NODE *list2){
    NODE *res = (NODE *)malloc(sizeof(NODE));
    NODE *cur = res;

    while(list1 && list2){
        if(list1->val <= list2->val){
            cur->next = list1;
            list1 = list1->next;
        }

        else{
            cur->next = list2;
            list2 = list2->next;
        }

        cur = cur->next;
    }

    if(list1)
        cur->next = list1;

    else
        cur->next = list2;

    return res->next;
}

void traverse(NODE **h){
    NODE *cur = *h;
    while(cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}

void insertBack(NODE **h, int val){
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

void insertFront(NODE **h, int val){
    NODE *newHead = (NODE *)malloc(sizeof(NODE));
    newHead->val = val;

    newHead->next = *h;
    *h = newHead;
}
