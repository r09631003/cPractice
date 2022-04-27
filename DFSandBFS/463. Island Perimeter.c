int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    
    int p = 0;
    
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1){
                
                if(i+1 >= gridSize || grid[i+1][j] != 1) p+=1;
                
                if(i-1 < 0 || grid[i-1][j] != 1) p+=1;
                
                if(j+1 >= *gridColSize || grid[i][j+1] != 1) p+=1;
                
                if(j-1 < 0 || grid[i][j-1] != 1) p+=1;
            }
        }
    }
    
    return p;
}
