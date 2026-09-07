class Solution {
public:
    void subSet(vector<int>& num,vector<int>& help,int i,vector<vector<int>>&ans){
        if(i==num.size()){
            ans.push_back({help});
            return;
        }
        help.push_back(num[i]);
        subSet(num,help,i+1,ans);
        help.pop_back();
        subSet(num,help,i+1,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> help;
        subSet(nums,help,0,ans);
        return ans;
    }
};