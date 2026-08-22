class Solution {
public:
    int pivit(vector<int>& nums, int st, int end){
        int piv = nums[end];
        int j=st-1;
        for(int i=st; i<end ;i++){
            if(nums[i]<piv){
                j++;
                swap(nums[i],nums[j]);
            }
        }
        j++;
        swap(nums[end], nums[j]);
        return j;
    }
    void QuickSort(vector<int>& nums, int st, int end){
        if(st>=end) return;
        int p = pivit(nums,st,end);
        QuickSort(nums, st,p-1);
        QuickSort(nums ,p+1 , end);
    }
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size()-1;
        QuickSort(nums, 0, n);
        int pro1 = nums[0]*nums[1];
        int pro2 = nums[n]*nums[n-1];
        return pro2-pro1;
    }
};