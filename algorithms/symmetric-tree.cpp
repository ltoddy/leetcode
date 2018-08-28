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
    bool isSymmetric(TreeNode* right, TreeNode* left)
    {
        if (right == nullptr && left == nullptr) return true;

        if (right == nullptr || left == nullptr) return false;

        if (right->val == left->val) return isSymmetric(right->right, left->left) && isSymmetric(right->left, left->right);

        return false;
    }

public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr) return true;

        return this->isSymmetric(root->right, root->left);
    }
};
