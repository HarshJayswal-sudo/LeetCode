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
    pair<int,int> helper(TreeNode* root){
        if(!root) return make_pair(0,0);
        pair<int,int>l = helper(root->left);
        pair<int,int>r = helper(root->right);
        int currH = max(l.first , r.first) + 1;
        int D = l.first + r.first + 1;
        int currD = max(max(l.second,r.second),D);
        return make_pair(currH,currD);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return ans.second-1;
    }
};