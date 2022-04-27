int numIslands(char** grid, int gridSize, int* gridColSize){
    int sum = 0;
    
    
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == '1'){
                
                sum += 1;
                
                helper(grid, gridSize, *gridColSize, i, j);
            }
        }
    }
    
    return sum;
}

void helper(char **s, int gridSize, int gridColSize, int i, int j){
    if(i < 0 || j < 0 || i >= gridSize || j >= gridColSize || s[i][j] != '1') return;
    
    *(*(s+i)+j) = '#';
    helper(s, gridSize, gridColSize, i + 1, j);
    helper(s, gridSize, gridColSize, i - 1, j);
    helper(s, gridSize, gridColSize, i, j + 1);
    helper(s, gridSize, gridColSize, i, j - 1);
    
   /* 
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridColSize; j++){
            printf("%c ", s[i][j]);
        }
        
        printf("\n");
    }*/
}
