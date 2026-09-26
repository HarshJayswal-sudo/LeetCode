class Solution {
public:
    int solv(int i, vector<int>& costs, vector<int>& memo){
        if(i==costs.size()) return 0;
        if(i> costs.size()) return INT_MAX;
        if(memo[i] != -1) return memo[i];
        int ans = INT_MAX;
        if(i+1<= costs.size()) ans =  min(ans,costs[i]+1 + solv(i+1, costs,memo));
        if(i+2<= costs.size()) ans = min(ans,costs[i+1]+4 + solv(i+2, costs,memo));
        if(i+3<= costs.size()) ans = min(ans,costs[i+2]+9 + solv(i+3, costs,memo));
        return memo[i] = ans;

    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n+1,-1);
        return solv(0,costs,memo);
    }
};