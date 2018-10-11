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
    bool isSameTree(TreeNode* a, TreeNode* b)
    {
        if (a == nullptr) {
            if (b == nullptr) return true;
            else return false;
        } else if (b == nullptr) {
            return false;
        } else {
            return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t)
    {
        if (s == nullptr || t == nullptr) return false;

        return this->isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
