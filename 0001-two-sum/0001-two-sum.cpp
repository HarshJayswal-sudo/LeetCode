class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int,int> map;
        for(int i =0;i<nums.size();i++){
            int sec = tar - nums[i];
            if(map.find(sec)!= map.end()){
                return{i,map[sec]};
            }
            map[nums[i]]=i;
        }
        return {-1};
    }
};