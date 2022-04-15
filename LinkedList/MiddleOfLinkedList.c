#include<stdio.h>

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

void insert(NODE **, int);
void traverse(NODE **);
NODE* midddle(NODE **);
NODE* middleII(NODE **);

int maxValInPrior(NODE **);

int main(){
    NODE *h = NULL;
    insert(&h, 1);
    insert(&h, 2);
    insert(&h, 3);
    insert(&h, 4);
    insert(&h, 5);
    //insert(&h, 6);

    traverse(&h);

    NODE *m = middleII(&h);

    traverse(&m);
}

/* Find the max Value in the prior half part of the linked list */
int maxValInPrior(NODE **h){
    NODE *slow = *h;
    NODE *fast = *h;
    int maxValue = (*h)->val;

    while(fast && fast->next){
        if(slow->val > maxValue)
            maxValue = slow->val;
        slow = slow->next;
        fast = fast->next->next;
    }

    return maxValue;
}


/*If even: Return prior middle*/
NODE* middleII(NODE **h){
    if(!(*h)) return;


    NODE *slow = *h;
    NODE *fast = (*h)->next;

    while(fast){
        fast = fast->next;
        if(fast){
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

/*If even: Return post middle*/
NODE* midddle(NODE **h){
    if(!(*h)) return;

    NODE *fast = *h;
    NODE *slow = *h;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

void insert(NODE **h, int val){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->val = val;
    n->next = NULL;

    if(!(*h))
        *h = n;
    else{
        NODE *c = *h;
        while(c->next){
            c = c->next;
        }
        c->next = n;
    }
}
