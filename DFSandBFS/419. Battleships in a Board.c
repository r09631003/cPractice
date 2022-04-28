
int countBattleships(char** board, int boardSize, int* boardColSize){
    int total = 0;
    
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            if(board[i][j] == 'X'){
                total++;
                helper(board, boardSize, *boardColSize, i, j);
            }
        }
    }
    
    return total;
}


void helper(char** b, int r, int c, int i, int j){
    if(i < 0 || j < 0 || i >= r || j >= c || b[i][j] != 'X') return;
    
    *(*(b+i)+j) = '#';
    helper(b, r, c, i+1, j);
    helper(b, r, c, i-1, j);
    helper(b, r, c, i, j+1);
    helper(b, r, c, i, j-1);
}
