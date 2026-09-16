class Solution {
public:
    int bfs(vector<vector<int>>& grid,int n,int m,int sr,int sc, vector<vector<bool>>& vis){
        int area = 1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        
        while(!q.empty()){
            pair<int,int> land = q.front();
            q.pop();

            if(land.first-1>=0 && grid[land.first-1][land.second] == 1 && !vis[land.first-1][land.second]){
                vis[land.first-1][land.second] =true;
                q.push({land.first-1,land.second});
                area++;
            }

            if( land.second-1>=0 && grid[land.first][land.second-1] == 1 && !vis[land.first][land.second-1]){
                vis[land.first][land.second-1] = true;
                q.push({land.first,land.second-1});
                area++;
            }

            if(land.first+1<n && grid[land.first+1][land.second] == 1 && !vis[land.first+1][land.second]){
                vis[land.first+1][land.second]=true;
                q.push({land.first+1,land.second});
                area++;
            }

            if(land.second+1<m && grid[land.first][land.second+1] == 1 && !vis[land.first][land.second+1]){
                vis[land.first][land.second+1] = true;
                q.push({land.first,land.second+1});
                area++;
            }
        }
        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    area = max(area,bfs(grid,n,m,i,j, vis));
                }
            }
        }
        return area;
    }
};