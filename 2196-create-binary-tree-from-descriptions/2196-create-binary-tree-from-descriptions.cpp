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
    void helper(TreeNode* root,vector<vector<int>>& d){
        if(root == nullptr) return;
        for(int i=0; i<d.size(); i++){
            if(root->val == d[i][0]){
                if(d[i][2] == 1){
                    root->left = new TreeNode(d[i][1]);
                }else{
                    root->right = new TreeNode(d[i][1]);
                }
            }
        }
        helper(root->left,d);
        helper(root->right,d);
    }
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        TreeNode* root;
        unordered_map<int, TreeNode*> node;
        unordered_set<int>child;
        for(int i=0;i<d.size();i++){
            child.insert(d[i][1]);
        }
        for(int i=0;i<d.size();i++){
            if(child.find(d[i][0])==child.end()){
                root = new TreeNode(d[i][0]);
                node[d[i][0]] = root;
            }
        }
        for(int i=0;i<d.size();i++){
            TreeNode* temp = new TreeNode(d[i][1]);
            node[d[i][1]] = temp;
        }
        for(int i=0;i<d.size(); i++){
            if(node.count(d[i][0])){
                TreeNode* temp = node[d[i][0]];
                if(d[i][2]==1){
                    temp->left = node[d[i][1]];
                }else{
                    temp->right = node[d[i][1]];
                }
            }
        }      
        return root;
        
    }
};