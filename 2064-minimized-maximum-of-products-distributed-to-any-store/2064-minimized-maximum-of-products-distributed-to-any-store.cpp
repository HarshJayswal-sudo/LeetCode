class Solution {
public:
    bool solve(int n, vector<int>& quantities, int item){
        if( item  == 0 ) return false;
        int store = 0;
        for(auto product : quantities){
            store += (product - 1) / item + 1;
            if(store > n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0;
        int  h = *max_element(quantities.begin(), quantities.end());
        int ans = -1;
        
        while(l<=h){
            int mid = (l+h)/2;
            if(solve(n,quantities, mid)){
                ans = mid;
                h = mid -1;
            }else{
                l = mid +1;
            }
        }
        return ans;
    }
};