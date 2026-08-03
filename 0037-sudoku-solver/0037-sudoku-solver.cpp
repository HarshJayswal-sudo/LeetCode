class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row,int col, int dig){
        for(int i=0;i<9;i++){
            if(board[i][col]== dig) return false;
        }
        for(int j=0;j<9;j++){
            if(board[row][j]==dig) return false;
        }
        int brow =(row/3)*3;
        int bcol =(col/3)*3;
        for(int i=brow;i<=brow+2;i++){
            for(int j=bcol;j<=bcol+2;j++){
                if(board[i][j]==dig) return false;
            }
        }
        return true;
    }
    bool sudoku(vector<vector<char>>& board, int row,int col){
        if(row==9){
            return true;
        }
        int nextrow = row;
        int nextcol = col+1;
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }
        if(board[row][col] != '.'){
            return sudoku(board,nextrow,nextcol);
        }
        for(int i='1';i<='9';i++){
            if(isSafe(board,row,col,i)){
                board[row][col]=i;
                if(sudoku(board,nextrow,nextcol)){
                    return true;
                }
                board[row][col]='.';
            }
            
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0);
    }
};