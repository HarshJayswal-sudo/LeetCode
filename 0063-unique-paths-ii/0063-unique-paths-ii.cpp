class Solution {
public:
    int recursion(int i, int j, int m, int n,vector<vector<int>>& o,vector<vector<int>>&dp){
        if((i==m-1) && (j == n-1)) return 1;
        if (i >= m || j >= n || o[i][j] == 1) return 0;
        int ans1=0,ans2=0;
        if(dp[i][j] != -1) return dp[i][j];
        
        
        ans1 = recursion(i+1,j,m,n,o,dp);        
        
        ans2 = recursion(i,j+1,m,n,o,dp);
    
        return dp[i][j] = ans1+ans2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o[0].size();
        int m = o.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recursion(0,0,m,n,o,dp);
    }
};