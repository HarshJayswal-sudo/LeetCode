class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int>m;
        priority_queue<pair<int,int>> vl;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            vl.push({it.second,it.first});
        }
        while(k>0){
            ans.push_back(vl.top().second);
            vl.pop();
            k--;
        }
        return ans;
    }
};