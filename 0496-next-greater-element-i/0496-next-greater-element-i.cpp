class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[i]<nums2[j]){
                    m[nums2[i]] = nums2[j];
                    break;
                }
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(m.find(nums1[i]) != m.end()){
                nums1[i] = m[nums1[i]];
            }else{
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};