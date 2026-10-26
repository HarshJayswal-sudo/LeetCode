class Solution {
public:
    int helper(vector<int>& nums, int st,int end, vector<vector<int>> &dp){
        if(st==end) return nums[st];
        if(dp[st][end] != 1e9) return dp[st][end];

        int ch1 = nums[st] - helper(nums,st+1,end,dp);
        int ch2 = nums[end] - helper(nums,st,end-1,dp);
        return dp[st][end] = max(ch1,ch2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n,vector<int>(n,1e9));
        int profit =  helper(nums,0,n-1,dp);    
        return (profit>=0);
    }
};