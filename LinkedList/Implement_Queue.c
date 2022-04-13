#include<stdio.h>
#include<stdbool.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node Queue;


bool isEmpty(Queue **);
void traverse(Queue **);
void enqueue(Queue **, Queue **, int);
int qSize(Queue **);
void dequeue(Queue **);

int main(){
    Queue *tail = NULL;
    Queue *head = NULL;

    enqueue(&head, &tail, 1);
    enqueue(&head, &tail, 2);
    enqueue(&head, &tail, 3);
    enqueue(&head, &tail, 4);
    enqueue(&head, &tail, 5);
    enqueue(&head, &tail, 7);
    enqueue(&head, &tail, 9);
    enqueue(&head, &tail, 10);
    enqueue(&head, &tail, 12);

    dequeue(&head);
    dequeue(&head);
    dequeue(&head);
    dequeue(&head);

    traverse(&head);

    int s = qSize(&head);
    printf("\nThe queue size is %d\n", s);

}

int qSize(Queue **h){
    int len = 0;
    Queue *c = *h;
    while(c){
        len++;
        c = c->next;
    }

    return len;
}

void dequeue(Queue **h){
    if(isEmpty(h)) return;

    Queue *tmp = *h;
    *h = (*h)->next;
    free(tmp);
}

void traverse(Queue **h){
    if(isEmpty(h)) return;

    Queue *c = *h;
    while(c){
        printf("%d ", c->val);
        c = c->next;
    }

    return;
}

void enqueue(Queue **h, Queue **t, int x){
    Queue *n = (Queue *)malloc(sizeof(Queue));
    n->val = x;
    n->next = NULL;

    if(isEmpty(h)){
        *h = n;
        *t = n;
    }

    else{
        (*t)->next = n;
        (*t) = n;
    }
}



bool isEmpty(Queue **h){
    return !(*h);
}
