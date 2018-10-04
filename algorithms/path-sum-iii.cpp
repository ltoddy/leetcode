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
    int traversal(TreeNode* root, int sum)
    {
        int res = 0;
        if (root == nullptr) return res;
        if (root->val == sum) res += 1;

        res += traversal(root->left, sum - root->val);
        res += traversal(root->right, sum - root->val);

        return res;
    }

public:
    int pathSum(TreeNode* root, int sum)
    {
        if (root == nullptr) return 0;
        return traversal(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
