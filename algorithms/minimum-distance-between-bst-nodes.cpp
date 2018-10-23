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
    int minDiffInBST(TreeNode* root)
    {
        int res = INT_MAX, pre = -1;
        stack<TreeNode*> s;
        TreeNode* tmp = root;
        while (!s.empty() || tmp != nullptr) {
            if (tmp != nullptr) {
                s.push(tmp);
                tmp = tmp->left;
            } else {
                tmp = s.top(), s.pop();
                if (pre != -1) res = min(res, tmp->val - pre);
                pre = tmp->val;
                tmp = tmp->right;
            }
        }
        return res;
    }
};
