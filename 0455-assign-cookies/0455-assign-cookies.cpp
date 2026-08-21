class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        int j = 0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        for(int i=0;i<g.size();i++){
            if(j == s.size()) break;
            while(j<s.size()){
                if(s[j]>=g[i]){
                    count++;
                    j++;
                    break;
                }
                j++;
            }
        }
        return count;
    }
};