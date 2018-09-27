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
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;

        TreeNode* root;
        if (t1 != nullptr && t2 == nullptr) root = new TreeNode(t1->val);
        else if (t2 != nullptr && t1 == nullptr) root = new TreeNode(t2->val);
        else root = new TreeNode(t1->val + t2->val);

        root->left = this->mergeTrees(t1->left, t2->left);
        root->right = this->mergeTrees(t1->right, t2->right);

        return root;
    }
};
