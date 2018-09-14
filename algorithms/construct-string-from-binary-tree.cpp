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
    string tree2str(TreeNode* t)
    {
        if (t == nullptr) return "";

        string res = to_string(t->val);
        if (t->left != nullptr) res += "(" + this->tree2str(t->left) + ")";
        else if (t->right != nullptr) res += "()";

        if (t->right != nullptr) res += "(" + this->tree2str(t->right) + ")";
        return res;
    }
};
