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
    int minDepth(TreeNode* root, int depth)
    {
        if (root == nullptr) return depth;

        if (root->left == nullptr && root->right != nullptr) {
            return minDepth(root->right, depth + 1);
        } else if (root->left != nullptr && root->right == nullptr) {
            return minDepth(root->left, depth + 1);
        } else {
            return min(minDepth(root->right, depth + 1), minDepth(root->left, depth + 1));
        }
    }

public:
    int minDepth(TreeNode* root)
    {
        return this->minDepth(root, 0);
    }
};
