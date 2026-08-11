class Solution {
public:
    void heapify(vector<int>& nums, int i, int n) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int maxelem = i;

        if (l < n && nums[maxelem] < nums[l])
            maxelem = l;
        if (r < n && nums[maxelem] < nums[r])
            maxelem = r;
        if (maxelem != i) {
            swap(nums[i], nums[maxelem]);
            heapify(nums, maxelem, n);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, i, n);
        }
        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
        return nums;
    }
};