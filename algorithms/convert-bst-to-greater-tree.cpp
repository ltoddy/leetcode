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
    int total = 0;

    void dfs(TreeNode* root)
    {
        if (root == nullptr) return;

        dfs(root->right);
        root->val += total;
        total = root->val;
        dfs(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root)
    {
        dfs(root);
        return root;
    }
};
