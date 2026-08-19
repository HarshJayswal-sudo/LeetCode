class Solution {
public:
    bool helper(vector<int>& nums, int tar, int st, int end){
        if(st>end) return false;
        int mid = st + (end - st)/2;
        if(nums[mid] == tar) return true;
        if(nums[st]==nums[mid] && nums[mid] == nums[end]){
            return helper(nums,tar,st+1, end-1);
        }
        if(nums[st]<=nums[mid]){
            if(nums[st] <= tar && tar < nums[mid]){
                return helper(nums,tar,st, mid-1);
            }else{
                return helper(nums,tar,mid+1,end);
            }
        }else{
            if(nums[mid] < tar && tar <= nums[end]){
                return helper(nums,tar,mid+1, end);
            }else{
                return helper(nums,tar,st,mid-1);
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int tar) {
        int st = 0, end = nums.size()-1;
        return helper(nums,tar,st, end);
    }
};