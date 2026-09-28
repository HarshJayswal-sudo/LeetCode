class Solution(object):
    def canJump(self, nums):
        ans = nums[0]
        for i in range(1,len(nums)):
            if ans >= i:
                ans = max(ans,i+nums[i])
            else:
                return False
        
        return True