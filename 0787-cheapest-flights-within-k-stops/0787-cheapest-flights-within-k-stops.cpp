class Info{
public:
    int u;
    int wt;
    int stops;
    Info(int u, int wt, int stops){
        this->u = u;
        this->wt = wt;
        this->stops = stops;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(n,INT_MAX);
        q.push(Info(src,0,-1));
        dist[src]= 0;
        while(!q.empty()){
            Info v = q.front();
            q.pop();
            for(int i=0;i<flights.size();i++){
                if(v.u == flights[i][0]){
                    int U= flights[i][1];
                    int W = flights[i][2];
                    if((dist[U]> v.wt + W) && (v.stops+1<=k)){
                        dist[U]= v.wt + W;
                        q.push(Info(U,dist[U],v.stops+1));
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};