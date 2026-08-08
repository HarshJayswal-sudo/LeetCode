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
    void inorder(TreeNode* root,vector<int>& order){
        if(root==nullptr) return;
        inorder(root->left,order);
        order.push_back(root->val);
        inorder(root->right,order);
    }
    TreeNode* helper(vector<int>& order,int i){
        if(i==order.size()) return nullptr;
        TreeNode* newroot = new TreeNode(order[i]);
        newroot->right = helper(order,i+1);
        return newroot;
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int>order;
        inorder(root,order);
        TreeNode* newRoot = helper(order,0);
        return newRoot;
    }
};