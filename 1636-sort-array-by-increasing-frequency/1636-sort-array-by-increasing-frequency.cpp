class Solution {
public:
    static bool compare( const pair<int,int>&a ,const pair<int,int> &b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>>hlp(m.begin(),m.end());
        sort(hlp.begin(),hlp.end(),compare);
        vector<int>anss;
        for(auto i:hlp){
            for(int j=0;j<i.second;j++){
            anss.push_back(i.first);
            }
        }
        return anss;
    }
};