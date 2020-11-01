/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode *> que;
        int last = 0;

        que.push(root);
        while (!que.empty()) {
            int length = que.size();
            int level = 0;

            for (int i = 0; i < length; i++) {
                TreeNode *node = que.front();
                que.pop();
                level += node->val;

                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            last = level;
        }

        return last;
    }
};
