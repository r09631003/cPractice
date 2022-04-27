/*

[["X","X","X","X"],
["X","O","O","X"],
["X","X","O","X"],
["X","O","X","X"]]

        |
        v

[["X","X","X","X"],
["X","X","X","X"],
["X","X","X","X"],
["X","O","X","X"]]

*/


void solve(char** board, int boardSize, int* boardColSize){
    
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            if((i == 0 || j == 0 || i == boardSize - 1 || j == *boardColSize-1) && (board[i][j] == 'O')){
                helper(board, boardSize, *boardColSize, i, j);
            }
        }
    }
    
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < *boardColSize; j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == '@') board[i][j] = 'O';
        }
    }
    
}

void helper(char **board, int boardSize, int boardColSize, int i, int j){
    if(i < 0 || j < 0 || i >= boardSize || j >= boardColSize || board[i][j] != 'O') return;
    
    *(*(board+i)+j) = '@';
    
    helper(board, boardSize, boardColSize, i+1, j);
    helper(board, boardSize, boardColSize, i-1, j);
    helper(board, boardSize, boardColSize, i, j+1);
    helper(board, boardSize, boardColSize, i, j-1);
}
