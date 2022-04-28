struct node{
    int val;
    struct node *next;
};

typedef struct node NODE;

bool isEmpty(NODE **);
void dequeue(NODE **);
int front(NODE **);
void enqueue(NODE **, NODE **, int);
int cntSize(NODE **);

int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int day = 0;
    NODE *h = NULL;
    NODE *t = NULL;
    int total = 0;
    
    # put the rotten apple index to the Queue, and record the amount of the fresh apple index
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1) total += 1;
            else if(grid[i][j] == 2){
                enqueue(&h, &t, i * (*gridColSize) + j);
            }
        }
    }
    
  
    while(!isEmpty(&h) && total > 0){
        
        # run 1 For Loop means "pass through 1 minitue". and the 4 directs fresh apple will be rotten by the apple in Queue.  
      
        for(int i = cntSize(&h); i > 0; --i){
            int pos = front(&h);
            dequeue(&h);
            int x = pos / (*gridColSize);
            int y = pos % (*gridColSize);

            if(x-1 >= 0 && grid[x-1][y] == 1){
                grid[x-1][y] = 2;
                enqueue(&h, &t, (x-1)*(*gridColSize) + y);
                total -= 1;
            }
            if(x+1 < gridSize && grid[x+1][y] == 1){
                grid[x+1][y] = 2;
                enqueue(&h, &t, (x+1)*(*gridColSize) + y);
                total -= 1;
            }
            if(y-1 >= 0 && grid[x][y-1] == 1){
                grid[x][y-1] = 2;
                enqueue(&h, &t, x*(*gridColSize) + y-1);
                total -= 1;
            }
            if(y+1 < *gridColSize && grid[x][y+1] == 1){
                grid[x][y+1] = 2;
                enqueue(&h, &t, x*(*gridColSize) + y+1);
                total -= 1;
            }
        }
        
        day += 1;
    }
    
    return (total == 0)?day:-1;
}

int cntSize(NODE **h){
    if(!(*h)) return;
    int sum = 0;

    NODE *c = *h;
    while(c){
        sum++;
        c = c->next;
    }

    return sum;
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
