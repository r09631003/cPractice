# Using BFS so need to implement Queue as the tempoary storage

struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;


void dequeue(NODE **);
int front(NODE **);
void enqueue(NODE **, NODE **, int );
bool isEmpty(NODE **);

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int visited[roomsSize];
    
    for(int i = 0; i < roomsSize; i++)
        visited[i] = 0;
    
    NODE *h = NULL;
    NODE *t = NULL;
    
    visited[0] = 1;
    for(int j = 0; j < *roomsColSize; j++){
        enqueue(&h, &t, *(*(rooms)+j));
    }
    
    while(!isEmpty(&h)){
        int f = front(&h);
        visited[f] = 1;
        
        for(int j = 0; j < *(roomsColSize+f); j++){
            if(visited[*(*(rooms+f)+j)] == 0){
                enqueue(&h, &t, *(*(rooms+f)+j));
            }
        }
        
        dequeue(&h);
    }
    
    
    for(int i = 0; i < roomsSize; i++){
        if(visited[i] == 0) return false; 
    }
    
    return true;
}

bool isEmpty(NODE **h){
    return !(*h);
}


void dequeue(NODE **h){
    if(!(*h)) return;

    NODE *tmp = *h;
    *h = (*h)->next;
    free(tmp);
}

int front(NODE **h){
    if(!(*h)) return;

    return (*h)->val;
}

void enqueue(NODE **h, NODE **t, int x){
    NODE *n = (NODE *)malloc(sizeof(NODE));
    n->val = x;
    n->next = NULL;

    if(!(*h)){
        *h = n;
        *t = n;
    }

    else{
        (*t)->next = n;
        *t = n;
    }
}
