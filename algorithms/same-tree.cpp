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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr || q == nullptr) {
            return p == q;
        } else {
            return p->val == q->val &&
                   this->isSameTree(p->left, q->left) &&
                   this->isSameTree(p->right, q->right);
        }
    }
};
