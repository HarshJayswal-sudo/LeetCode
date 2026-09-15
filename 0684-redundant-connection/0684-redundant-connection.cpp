class dsu{
public:
    int V;
    vector<int>par;
    vector<int>rank;
    dsu(int V){
        this->V = V;
        for(int i=0;i<V;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }

    void unionRank(int a,int b){
        int parA = find(a);
        int parB = find(b);

        if(rank[parA] == rank[parB]){
            par[parB] = parA; 
            rank[parA]++;
        } else if(rank[parA]<rank[parB]){
            par[parA]=parB;
        } else{
            par[parB]=parA;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu DSU(edges.size()+1);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            if(DSU.find(u) == DSU.find(v)){
                return {u,v};
            }
            DSU.unionRank(u,v);
        }
        return{};
    }
};