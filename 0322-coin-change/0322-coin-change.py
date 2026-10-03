class Solution(object):
    def coinChange(self, coins, amount):
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(0,len(coins)):
            for j in range(coins[i],amount+1):
                dp[j] = min(dp[j],dp[j-coins[i]]+1)           
        if dp[amount] != float('inf'):
            return dp[amount]
        return -1
        