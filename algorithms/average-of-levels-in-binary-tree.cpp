/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        if (root == nullptr) return {};

        vector<double> averages;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            long sum = 0;
            int total = que.size();
            for (int i = 0; i < total; i++) {
                TreeNode* tmp = que.front();
                que.pop();
                if (tmp->left != nullptr) que.push(tmp->left);
                if (tmp->right != nullptr) que.push(tmp->right);
                sum += tmp->val;
            }
            averages.push_back(static_cast<double>(sum) / total);
        }
        return averages;
    }
};
