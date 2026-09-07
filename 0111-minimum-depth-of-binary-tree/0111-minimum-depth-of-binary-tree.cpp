class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        if(root->left==NULL && root->right==NULL)  return 1;
        int left=minDepth(root->left);
        int right = minDepth(root->right);
        if(root->left==nullptr) return 1+right;
        if(root->right==nullptr) return 1+left;
        int curr = min(left,right)+1;
        return curr;
    }
};