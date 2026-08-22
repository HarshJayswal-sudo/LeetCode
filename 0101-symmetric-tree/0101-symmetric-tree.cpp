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
     bool helper(TreeNode* leftX, TreeNode* rightX){
        if(leftX == NULL && rightX == NULL) return true;
        if(leftX ==NULL || rightX == NULL) return false;
        if(leftX->val != rightX->val) return false;
        return helper(leftX->left, rightX->right) && helper(leftX->right,rightX->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};