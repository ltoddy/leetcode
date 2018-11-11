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
private:
    int traversal(TreeNode* node, int value)
    {
        if (node == nullptr || node->val != value) return 0;

        return 1 + max(traversal(node->left, value), traversal(node->right, value));
    }

public:
    int longestUnivaluePath(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int tmp = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(tmp, traversal(root->left, root->val) + traversal(root->right, root->val));
    }
};
