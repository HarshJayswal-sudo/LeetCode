class Solution {
public:
    bool isValid(vector<int>& weights, int days, int wt) {
        int currday = 1;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= wt) {
                sum += weights[i];
            } else {
                currday++;
                sum = weights[i];
            }
        }
        return currday <= days ? true : false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans;
        int end = 0;
        int st = INT_MIN;
        for (int i = 0; i < weights.size(); i++) {
            end += weights[i];
            st = max(weights[i], st);
        }
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isValid(weights, days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};