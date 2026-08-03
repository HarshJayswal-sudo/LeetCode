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
class info{
public :
    bool isBST;
    int maxNode,minNode,sum;

    info(bool isBST,int minNode,int maxNode,int sum){
        this->isBST=isBST;
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    }
};

class Solution {
public:
    info* helper(TreeNode* root,int& ans){
        if(root==nullptr) return new info(true,INT_MAX,INT_MIN,0);
        info* leftside = helper(root->left,ans);
        info* rightside = helper(root->right,ans);
        int currmax= max(root->val,max(leftside->maxNode,rightside->maxNode));
        int currmin= min(root->val,min(leftside->minNode,rightside->minNode));
        int currsum = leftside->sum + rightside->sum + root->val;
        if(leftside->isBST && rightside->isBST 
          && root->val > leftside->maxNode  &&  root->val < rightside->minNode){
            ans= max(ans,currsum);
            return new info (true,currmin,currmax,currsum); 
        }
        return new info(false,currmin,currmax,currsum);
    }

    int maxSumBST(TreeNode* root) {
        int ans=0;
        helper(root,ans);
        return ans;
    }
};