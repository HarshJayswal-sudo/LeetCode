class Solution {
public:
    bool isSafe(int n, vector<string>board,int row , int col){
        for(int i = 0;i<col;i++){
            if(board[row][i] == 'Q') return false;
        }
        for(int i = 0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }

        for(int i = row,j= col ; i>=0 && j>=0 ; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row,j= col ; i>=0 && j<n ; i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    int solver(int n, vector<string>board,int row ){
        if(row == n){
            return 1;
        }
        int count = 0;
        for(int j=0; j<n; j++){
            if(isSafe(n,board,row,j)){
                board[row][j] = 'Q';
                count += solver(n,board,row+1);
                board[row][j] = '.';
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        return solver(n,board,0);
    }
};