class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int maxSum = INT_MIN;
        int answer = 1;

        while (!q.empty()) {

            int size = q.size();
            int sum = 0;

            for (int i = 0; i < size; i++) {

                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                answer = level;
            }

            level++;
        }

        return answer;
    }
};
