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
    int maxDepth(TreeNode* root, int depth)
    {
        if (root == nullptr) return depth;

        return max(maxDepth(root->right, depth + 1), maxDepth(root->left, depth + 1));
    }

public:
    int maxDepth(TreeNode* root)
    {
        return this->maxDepth(root, 0);
    }
};
