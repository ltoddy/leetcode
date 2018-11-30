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
    TreeNode* dfs(vector<int>& inorder, int in_l, int in_r, vector<int>& postorder, int post_l, int post_r)
    {
        if (in_l > in_r) return nullptr;

        TreeNode* root = new TreeNode(postorder[post_r]);
        int pos = in_l;
        while(inorder[pos] != postorder[post_r] && pos < in_r) pos++;

        root->left = dfs(inorder, in_l, pos - 1, postorder, post_l, post_l + pos - in_l - 1);
        root->right = dfs(inorder, pos + 1, in_r, postorder, post_l + pos - in_l, post_r - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return dfs(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
