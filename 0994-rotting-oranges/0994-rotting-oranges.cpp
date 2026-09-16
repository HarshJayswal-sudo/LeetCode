class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Push all rotten oranges and count fresh ones
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0; // no fresh oranges

        int time = -1;
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,-1,0,1};

        // BFS level by level
        while(!q.empty()){
            int sz = q.size();
            time++;
            for(int i=0;i<sz;i++){
                auto [x,y] = q.front(); q.pop();
                for(int d=0; d<4; d++){
                    int nx = x + dx[d], ny = y + dy[d];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        grid[nx][ny] = 2; // mark rotten
                        fresh--;
                        q.push({nx,ny});
                    }
                }
            }
        }

        return fresh==0 ? time : -1;
    }
};
