class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n+1;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<m+1;i++){
            dp[0][i] = 0;
        }

        for(int i=1;i< n+1;i++){
            for(int j =1;j< m+1;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);   
            }
        }
        return ans;
    }
};