class Solution(object):
    def numSquares(self, n):
        dp = [10**4]*(n+1)#at any indx i we will store the least no of square numbers that sum equal to num
        dp[0] = 0
        for i in range(1,n+1):
            for j in range(i,0,-1):
                k = j**0.5
                if k%1 == 0:
                    dp[i] = min(dp[i],dp[i-j]+1)
        return dp[n]