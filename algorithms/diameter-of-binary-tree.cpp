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
    int maxd = 0;

    int dfs(TreeNode* node)
    {
        if (node == nullptr) return 0;

        int l = this->dfs(node->left), r = this->dfs(node->right);

        maxd = max(this->maxd, l + r);

        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr) return 0;

        dfs(root);
        return this->maxd;
    }
};
