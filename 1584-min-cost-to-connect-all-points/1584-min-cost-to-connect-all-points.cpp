class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int cost = 0;
        vector<int>vis(n, false);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>  pq;
        pq.push(make_pair(0,0));

        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(!vis[u]){
                vis[u]= true;
                cost += wt;
                for(int i=0;i<n;i++){
                    if(u != i){
                        wt = abs(points[u][0]-points[i][0])+abs(points[u][1]-points[i][1]);
                        pq.push(make_pair(wt,i));
                    }
                }
            }
        }
        return cost;
    }
};