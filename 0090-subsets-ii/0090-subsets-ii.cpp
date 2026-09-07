class Solution {
public:
    void helper(vector<int>& nums,int i,vector<int>& ans,vector<vector<int>>&s){
        if(i==nums.size()){
            s.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        helper(nums,i+1,ans,s);
        ans.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        helper(nums,idx,ans,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>s;
        vector<int>ans;
        helper(nums,0,ans,s);
        return s;
    }
};