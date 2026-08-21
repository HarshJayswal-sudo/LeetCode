/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root){
        if(root == nullptr) return 1;
        int left = helper(root->left);
        int right = helper(root->right);
        if(abs(left - right) > 1) return 0;
        int curr = max(left,right)+1; 
        if(right == 0 || left == 0) return 0;        
        if(abs(left - right) > 1) return 0;
        return curr;
    }

    bool isBalanced(TreeNode* root) {
        return helper(root);
    }
};