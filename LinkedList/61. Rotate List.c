#include<stdio.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

void create(NODE **, int *, int);
void traverse(NODE **);
int getLength(NODE **);

NODE *rotateRight(NODE *, int);

int main(){
    int arr[] = {1,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    NODE *head = NULL;
    create(&head, arr, len);
    traverse(&head);
    NODE *r = rotateRight(head, 1);
    traverse(&r);
}

NODE *rotateRight(NODE *head, int k){
    if(!head || !(head->next)) return;
    int len = getLength(&head);
    NODE *cur = head;

    k = k % len;
    if(k == 0) return head;

    k = len - k;
    k = k - 1;

    while(k > 0){
        cur = cur->next;
        k--;
    }

    NODE *post = cur->next;
    NODE *pc = post;
    cur->next = NULL;

    while(pc->next)
        pc = pc->next;

    pc->next = head;

    return post;
}

int getLength(NODE **head){
    int len = 0;
    NODE *cur = *head;
    while(cur){
        len++;
        cur = cur->next;
    }
    return len;
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

void traverse(NODE **head){
    if(!(*head)) return;
    NODE *cur = *head;
    while(cur){
        printf("%d ", cur->val);
        cur = cur->next;
    }

    printf("\n");
}
