class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0,k));
        dist[k]=0;
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            int u = p.second;
            pq.pop();
            for(int i=0;i<times.size();i++){
                if(u == times[i][0]){
                    int v = times[i][1];
                    if(dist[u]+times[i][2]<dist[v]){
                        dist[v] = dist[u]+times[i][2];
                        pq.push(make_pair(dist[v],v));
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i =1; i<=n;i++){
        if(dist[i] == INT_MAX) return -1;
        ans= max(ans,dist[i]);
        }
        return ans;

    }
};