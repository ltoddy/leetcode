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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (root == nullptr) return {};

        vector<vector<int>> result;
        queue<TreeNode*> que;
        que.push(root);
        int counter = 0;

        while (!que.empty()) {
            int length = que.size();
            vector<int> tmp;

            while (length--) {
                TreeNode* node = que.front();
                que.pop();
                tmp.push_back(node->val);

                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }

            if (counter % 2 == 1) reverse(tmp.begin(), tmp.end());
            counter++;
            result.push_back(tmp);
        }

        return result;
    }
};
