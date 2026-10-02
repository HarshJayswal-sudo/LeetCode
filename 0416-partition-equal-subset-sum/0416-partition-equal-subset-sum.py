class Solution(object):
    def canPartition(self, nums):
        n = len(nums)
        target = sum(nums)
        if target%2 != 0:
            return False
        else:
            target = target//2
        dp = [[False]*(target+1) for _ in range(n+1)]

        for i in range(0,n+1):
            dp[i][0] = True
        dp[0][0] = True
        
        for i in range(1,n+1):
            for j in range(1,target+1):
                dp[i][j] = dp[i-1][j]
                if(j>= nums[i-1]):
                     dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]]
                
        
        return dp[n][target]

        