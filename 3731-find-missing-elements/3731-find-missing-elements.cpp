class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s;
        int mx = INT_MIN;
        int mn = INT_MAX;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
            mx = max(mx,nums[i]);
            mn = min(mn,nums[i]);
        }
        for(int j=mn;j<=mx;j++){
            auto it = s.find(j);
            if(it == s.end()){
                ans.push_back(j);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};