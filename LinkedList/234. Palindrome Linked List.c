#include<stdio.h>
#include<stdbool.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

void push(NODE **, int);
void traverse(NODE **);
int top(NODE **);
void pop(NODE **);
void createLinked(NODE **, int *, int);
bool isPalindrome(NODE*);

int main(){
    NODE *h = NULL;
    int arr[] = {1,3,3,5};
    int len = sizeof(arr)/sizeof(arr[0]);

    createLinked(&h, arr, len);


    traverse(&h);

    bool ans = isPalindrome(h);
    printf("isPalindrome: %s\n", ans?"True":"False");
}

bool isPalindrome(NODE* head){
    NODE *slow = head;
    NODE *fast = head;
    NODE *s = NULL;

    while(fast && fast->next){
        push(&s, slow->val);
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast) slow = slow->next;

    while(slow){
        if(slow->val != top(&s)) return false;
        pop(&s);
        slow = slow->next;
    }

    traverse(&s);

    return true;
}

void createLinked(NODE **h, int *arr, int len){
    NODE *prev;

    for(int i = 0; i < len; i++){
        NODE *cur = (NODE *)malloc(sizeof(NODE));
        cur->val = arr[i];

        if(i == 0)
            *h = cur;
        else
            prev->next = cur;

        cur->next = NULL;
        prev = cur;
    }
}

void pop(NODE **h){
    if(!(*h)) return;

    NODE *tmp = *h;
    *h = (*h)->next;
    free(tmp);
}

int top(NODE **h){
    if(!(*h)) return -1;

    return (*h)->val;
}

void push(NODE **h, int x){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->val = x;
    n->next = NULL;

    if(!(*h)) *h = n;
    else{
        n->next = *h;
        *h = n;
    }
}

void traverse(NODE **h){
    if(!(*h)) return;
    NODE *c = *h;

    while(c){
        printf("%d ", c->val);
        c = c->next;
    }

    printf("\n");
}
