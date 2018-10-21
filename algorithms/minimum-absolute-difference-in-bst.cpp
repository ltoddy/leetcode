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
    vector<int> values;

    void traversal(TreeNode* root)
    {
        if (root == nullptr)
            return;

        this->values.push_back(root->val);
        if (root->left != nullptr) traversal(root->left);
        if (root->right != nullptr) traversal(root->right);
        return;
    }

public:
    int getMinimumDifference(TreeNode* root)
    {
        this->traversal(root);
        sort(this->values.begin(), this->values.end());
        int res = INT_MAX;
        for (int i = 0; i < this->values.size() - 1; i++)
            res = min(res, abs(this->values[i] - this->values[i + 1]));
        return res;
    }
};
