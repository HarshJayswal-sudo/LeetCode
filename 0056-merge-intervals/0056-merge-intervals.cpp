class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        vector<int> pre = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(pre[1] >= intervals[i][0]){
                pre[1]=max(pre[1],intervals[i][1]);
            }else {
                ans.push_back(pre);
                pre = intervals[i];
            }
        }
        ans.push_back(pre);
        return ans;
    }
};