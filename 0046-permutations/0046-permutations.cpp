class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,int i){
        if(i==nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int j = i;j<nums.size();j++){
        swap(nums[j],nums[i]);
        helper(nums,ans,i+1);
        swap(nums[j],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>help;
        helper(nums,ans,0);
        return ans;
    }
};