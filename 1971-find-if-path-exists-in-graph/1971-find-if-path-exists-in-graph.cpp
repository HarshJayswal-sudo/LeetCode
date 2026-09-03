class Solution {
public:

    bool bfs(int n,int source, int dest, unordered_map<int, vector<int>> graph){
        queue<int>q;
        vector<bool>vis(n,false);

        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vector<int> l = graph[u];
            for(int v : l){
                if(!vis[v]){
                    if(v == dest) return true;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        if(source == dest) return true;
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return bfs(n,source,dest,graph);

    }
};