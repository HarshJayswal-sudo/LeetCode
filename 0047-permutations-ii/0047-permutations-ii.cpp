class Solution {
public:
   void helper(vector<int>& nums, int idx, set<vector<int>>& st) {

    if(idx == nums.size()) {
        st.insert(nums);
        return;
    }

    for(int i = idx; i < nums.size(); i++) {

        swap(nums[i], nums[idx]);

        helper(nums, idx + 1, st);

        swap(nums[i], nums[idx]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {

    set<vector<int>> st;

    helper(nums, 0, st);

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}
};