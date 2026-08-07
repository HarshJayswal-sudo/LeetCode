class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pev = -1, n = nums.size();
        if(n==1) return;
        for(int i= n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pev = i;
                break;
            }
            
        }
        if(pev == -1 ){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i = n-1; i>pev;  i--){
            if(nums[pev]<nums[i]){
                swap(nums[pev],nums[i]);
                break;
            }
        }
        int i=pev+1,j=n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;j--;
        }
        return;
    }
};