class Solution {
public:
    int helper(int st, int end, string &s, vector<vector<int>> &dp){
        if(st == end) return 1;
        if(st>end) return 0;
        if(dp[st][end] != -1){
            return dp[st][end];
        }
        if(s[st] == s[end]){
            dp[st][end] = helper(st+1,end-1,s,dp)+2;
        }else{
            dp[st][end] = max(helper(st+1,end,s,dp),helper(st,end-1,s,dp));
        }
        return dp[st][end];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,n-1, s, dp);
    }
};