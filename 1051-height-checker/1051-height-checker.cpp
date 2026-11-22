class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> clone = heights;
        int dif = 0;
        sort(clone.begin(),clone.end());
        for(int i=0; i<clone.size(); i++){
            if(clone[i] != heights[i]){
                dif++;
            }
        }
        return dif;
    }
};