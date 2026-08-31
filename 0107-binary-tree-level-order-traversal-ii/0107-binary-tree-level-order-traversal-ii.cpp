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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(root == NULL)
        return {};

        queue<TreeNode*> help;
        vector<vector<int>> ans;
        vector<int>lev;
        help.push(root);
        help.push(NULL);
        while(!help.empty()){
            TreeNode* currnode = help.front();
            if(currnode == NULL){
                help.pop();
                ans.push_back(lev);
                lev.clear();
                if(help.empty()){
                    break;
                }
                help.push(NULL);
            }else{
                lev.push_back(currnode->val);
                help.pop();
                if(currnode->left!=NULL){
                    help.push(currnode->left);
                }
                if(currnode->right!=NULL){
                    help.push(currnode->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};