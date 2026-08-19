class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& candidates, int tar, int i,
                vector<vector<int>>& ans, vector<int>& temp) {
        if (tar == 0) {
            if (s.find(temp) == s.end()) {
                ans.push_back(temp);
                s.insert(temp);
            }
            return;
        }
        if (tar < 0||i>= candidates.size()) return;
        
        temp.push_back(candidates[i]);
        helper(candidates, tar - candidates[i], i + 1, ans, temp);
        temp.pop_back();
        int idx = i + 1;
        while (idx < candidates.size() && candidates[idx] ==
                   candidates[i]) {
            idx++;
        }
        helper(candidates, tar, idx, ans, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int tar) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        helper(candidates, tar, 0, ans,temp);
        return ans;
    }
};