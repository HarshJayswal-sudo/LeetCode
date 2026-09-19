class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : redEdges) adj[e[0]].push_back({e[1], 0}); // 0 = red
        for (auto &e : blueEdges) adj[e[0]].push_back({e[1], 1}); // 1 = blue

        vector<vector<bool>> vis(n, vector<bool>(2,false));
        vector<int> ans(n, -1);
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({0,1});
        vis[0][0]=vis[0][1] = true;
        int len = 0;
        
        ans[0]=0;
        while(!q.empty()){
            int qlen = q.size();
            for(int i=0;i<qlen;i++){
                auto [node,color]=q.front();
                q.pop();
                if(ans[node] == -1) ans[node] = len;
                for(auto [nei,col] : adj[node]){
                    if(!vis[nei][col] && color != col){
                        vis[nei][col] = true;
                        q.push({nei,col});
                    }
                }
            }
            len++;
            
        }
        return ans;
    }
};