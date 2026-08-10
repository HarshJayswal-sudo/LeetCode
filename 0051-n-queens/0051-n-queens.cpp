class Solution {
public:
    bool isSafe(int n, int row, int col, vector<string>& presentAns){
        for(int i=0;i<n;i++){
            if(presentAns[i][col]=='Q') return false;
        }
        for(int j=0;j<n;j++){
            if(presentAns[row][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(presentAns[i][j]=='Q') return false;
        }
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(presentAns[i][j]=='Q') return false;
        }
        return true;
    }
    void helper(int n, int row,vector<vector<string>>& ans,vector<string>& presentAns){
        if(row==n) return ans.push_back(presentAns);
        for(int j=0;j<n;j++){
            if(isSafe(n,row,j,presentAns)){
                presentAns[row][j]='Q';
                helper(n,row+1,ans,presentAns);
                presentAns[row][j]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>help(n,string(n,'.'));
        helper(n,0,ans,help);
        return ans;
    }
};