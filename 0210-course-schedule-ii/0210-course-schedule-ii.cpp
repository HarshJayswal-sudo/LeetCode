class Solution {
public:
    void inoder(vector<int>& ino,vector<vector<int>>& edg){
        for(int i=0;i<edg.size();i++){
            ino[edg[i][0]]++;
        }
    }
    vector<int> khans(vector<int>& ino,vector<vector<int>>& edg){
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<ino.size();i++){
            if(ino[i]==0) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int i=0;i<edg.size();i++){
                if(u == edg[i][1]){
                    ino[edg[i][0]]--;
                    if(ino[edg[i][0]] == 0){
                        q.push(edg[i][0]);
                    }
                }
            }
        }
        return ans;
    }
    vector<int> findOrder(int n, vector<vector<int>>& edg) {
        vector<int>ino(n, 0);
        inoder(ino,edg);
        vector<int> ans=khans(ino,edg);
        return ans.size() == n ? ans : vector<int>();
    }
};