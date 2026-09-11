class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int st, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }
        vector<double> prob(n, 0.0);
        priority_queue<pair<double,int>>pq;
        prob[st] = 1.0;
        pq.push(make_pair(1.0,st));
        while(!pq.empty()){
            int u = pq.top().second;
            double wt = pq.top().first;
            pq.pop();
            if (u== end) return wt;
            for( auto [v, p]: adj[u]){
                if(wt*p>prob[v]){
                    prob[v]= wt*p;
                    pq.push(make_pair(prob[v],v));
                }
            }
            
        }
        return 0.0;
    }
};