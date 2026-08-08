class Solution {
public:
    set<vector<int>>s;
    void helper(vector<int>& arr, int tar, int i,vector<vector<int>>&ans,vector<int>& user){
        if(i==arr.size() || tar<0) {
            return;
        }
        if(tar==0){
            if(s.find(user)==s.end()){
                ans.push_back({user});
                s.insert(user);
            }
            return;
            
        }
        user.push_back(arr[i]);
        helper(arr,tar-arr[i],i+1,ans,user);
        helper(arr,tar-arr[i],i,ans,user);
        user.pop_back();
        helper(arr,tar,i+1,ans,user);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>>ans;
        vector<int> user;
        helper(arr,tar,0,ans,user);
        return ans;
    }
    
};