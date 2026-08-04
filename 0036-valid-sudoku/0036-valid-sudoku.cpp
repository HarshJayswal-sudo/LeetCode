class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r,int c){
        int ch = board[r][c];
        for(int i=0;i<9;i++){
            if(i!=r && board[i][c]==ch) return false;
        }
        for(int j=0;j<9;j++){
            if( j!=c &&board[r][j]==ch) return false;
        }
        int boxr = (r/3)*3;
        int boxc = (c/3)*3;
        for(int i= boxr;i<=boxr+2;i++){
            for(int j= boxc;j<=boxc+2;j++){
                if ((i != r || j != c) && board[i][j] == ch) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValid(board, i ,j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};