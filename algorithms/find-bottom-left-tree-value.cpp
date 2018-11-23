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
private:
    int traversal(TreeNode* root)
    {
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> nums;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
                nums.push_back(node->val);
            }

            if (que.size() == 0) return nums[0];
        }
    }

public:
    int findBottomLeftValue(TreeNode* root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return root->val;
        return this->traversal(root);
    }
};
