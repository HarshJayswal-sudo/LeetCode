class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int n,int m, int sr, int sc, vector<vector<bool>>& vis){
        if(sr == 0 || sc ==0 ||sr == n-1 || sc == m-1) return false;
        grid[sr][sc] = true;
        bool isClosed = true;

        if(sr-1>=0 && grid[sr-1][sc] == 0 && !vis[sr-1][sc]){
            isClosed = dfs(grid,n,m,sr-1,sc,vis) && isClosed;
        }

        if(sc-1>=0 && grid[sr][sc-1] == 0 && !vis[sr][sc-1]){
            isClosed = dfs(grid,n,m,sr,sc-1,vis) && isClosed;
        }

        if(sr+1<n && grid[sr+1][sc] == 0 && !vis[sr+1][sc]){
            isClosed = dfs(grid,n,m,sr+1,sc,vis) && isClosed;
        }

        if(sc+1<m && grid[sr][sc+1] == 0 && !vis[sr][sc+1]){
            isClosed = dfs(grid,n,m,sr,sc+1,vis) && isClosed;
        }

        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m =grid[0].size();
        int ans =0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=1; i<n-1; i++){
            for(int j=1;j<m-1; j++){
                if(grid[i][j]==0){
                    if(dfs(grid,n,m,i,j,vis)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};