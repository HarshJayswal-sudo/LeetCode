class Solution {
public:
    void merge (vector<int>& nums1,int n, vector<int>& nums2,int m,vector<int>& num){
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                num.push_back(nums1[i]);
                i++;
            }else{
                num.push_back(nums2[j]);
                j++;
            }
        }
        while(j<m){
            num.push_back(nums2[j]);
            j++;
        }
        while(i<n){
            num.push_back(nums1[i]);
            i++;
        }
        return;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>num;
        merge(nums1,n,nums2,m,num);
        int st = 0;
        int end = num.size()-1;
        int mid = st+(end-st)/2;
        double median = 0;
        if((n+m)% 2 == 0){
            median = (num[mid]+num[mid+1])/2.0;
        }else{
            median = num[mid];
        }
        return median;
    }
};