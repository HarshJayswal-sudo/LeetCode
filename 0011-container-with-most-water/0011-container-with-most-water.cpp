class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = INT_MIN;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            int w = r - l;
            int ht = min(height[l], height[r]);
            int area = w * ht;

            maxarea = max(area, maxarea);

            height[l] < height[r] ? l++ : r--;
        }

        return maxarea;
    }
};