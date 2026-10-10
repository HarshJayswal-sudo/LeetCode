class Solution {
public:
    int helper(int indx, bool canbuy, int fee, vector<int>& prices,
               vector<vector<int>>& dp) {
        if (indx == prices.size())
            return 0;
        if (dp[canbuy][indx] != -1)
            return dp[canbuy][indx];
        int ans = INT_MIN;
        if (canbuy) {
            ans = max(ans,
                      helper(indx + 1, false, fee, prices, dp) - prices[indx]);
        } else {
            ans = max(ans, helper(indx + 1, true, fee, prices, dp) +
                               prices[indx] - fee);
        }
        ans = max(ans, helper(indx + 1, canbuy, fee, prices, dp));
        dp[canbuy][indx] = ans;
        return ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n , -1));
        return helper(0, true, fee, prices, dp);
    }
};