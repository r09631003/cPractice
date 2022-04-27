#define max(A, B) (((A)>=(B))?(A):(B))

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int area = 0;
    int maxArea = 0;
    
    
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1){
                area = 0;
                helper(grid,  gridSize, *gridColSize, i, j, &area);
                maxArea = max(maxArea, area);
            }
        }
    }
    
    
    return maxArea;
}

void helper(int **grid, int gridSize, int gridColSize, int i, int j, int* area){
    if(i < 0 || j < 0 || i >= gridSize || j >= gridColSize || grid[i][j] != 1) return;
    (*area) += 1;
    *(*(grid+i)+j) = -1;
    
    helper(grid,  gridSize, gridColSize, i + 1, j, area);
    helper(grid,  gridSize, gridColSize, i - 1, j, area);
    helper(grid,  gridSize, gridColSize, i, j + 1, area);
    helper(grid,  gridSize, gridColSize, i, j - 1, area);
}
