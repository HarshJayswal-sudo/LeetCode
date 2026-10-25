class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]>nums[j]){
                    int currlen = dp[i];
                    int NewLen = dp[j]+1;

                    if(NewLen == currlen){
                        count[i] += count[j];
                    }else if(NewLen > currlen){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                }
            }
            ans = max(dp[i],ans);
        }
        int ctr =0;
        for(int i=0;i<n;i++){
            if(dp[i] == ans) ctr+=count[i];
        }
        return ctr;
    }
};