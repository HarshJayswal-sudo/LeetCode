class Solution {
public:
    int trap(vector<int>& height) {
        int watertrap=0;
        int n = height.size();
        vector<int> leftheight(n);
        vector<int> rightheight(n);
        leftheight[0]=INT_MIN;
        rightheight[n-1]=INT_MIN;
        for(int i=1; i<n;i++){
            leftheight[i]=max(leftheight[i-1], height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
                        rightheight[i]=max(rightheight[i+1], height[i+1]);
        }
        for(int i=1;i<n-1;i++){
            int current = min(leftheight[i],rightheight[i]) - height[i];
            if(current>0){
                watertrap+= current;
            }
             
        }
        return watertrap;
        
    }
};