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
    int depth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = this->depth(root->left);
        int right = this->depth(root->right);
        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr) return true;

        if (abs(this->depth(root->left) - this->depth(root->right)) > 1) return false;
        else return this->isBalanced(root->left) && this->isBalanced(root->right);
    }
};
