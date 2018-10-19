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
    int res = 0;

    int traversal(TreeNode* node)
    {
        if (node == nullptr) return 0;

        int left = this->traversal(node->left);
        int right = this->traversal(node->right);
        this->res += abs(left - right);
        return left + right + node->val;
    }

public:
    int findTilt(TreeNode* root)
    {
        this->traversal(root);
        return this->res;
    }
};
