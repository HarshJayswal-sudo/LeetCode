class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> a;
        a.push_back(1);
        for (int x : nums) a.push_back(x);
        a.push_back(1);

        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int length = 2; length < n; length++) {
            for (int i = 0; i + length < n; i++) {
                int j = i + length;
                for (int k = i + 1; k < j; k++) {  
                    int coins = dp[i][k] + a[i] * a[k] * a[j] + dp[k][j];
                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }

        return dp[0][n - 1];
    }
};