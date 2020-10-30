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
    int maxLevelSum(TreeNode *root) {
        if (root == nullptr) {
            return -1;
        }

        int depth = 0;
        vector<pair<int, int>> levels;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int length = que.size();
            vector<int> level;
            depth += 1;
            for (int i = 0; i < length; i++) {
                TreeNode *node = que.front();
                que.pop();
                level.push_back(node->val);

                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            levels.emplace_back(depth, accumulate(level.begin(), level.end(), 0));
        }

        int maxsum = INT_MIN;
        int maxdepth = 0;
        for (auto &level : levels) {
            if (maxsum < level.second) {
                maxsum = level.second;
                maxdepth = level.first;
            }
        }

        return maxdepth;
    }
};
