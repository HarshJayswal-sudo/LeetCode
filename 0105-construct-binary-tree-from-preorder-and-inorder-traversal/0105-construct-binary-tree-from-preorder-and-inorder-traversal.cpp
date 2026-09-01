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
int z=0;
    TreeNode* helper(vector<int>& preorder,int &z, vector<int>& inorder,int i,int j){
        if(i>j) return NULL;
        TreeNode* root = new TreeNode(preorder[z]);
        z++;
        int t;
        for(t =i;t<=j;t++){
            if(inorder[t]==preorder[z-1]) break;
        }
        root->left = helper(preorder,z,inorder,i,t-1);
        root->right = helper(preorder,z,inorder,t+1,j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=helper(preorder,z,inorder,0,inorder.size()-1);
        return root;
    }
};