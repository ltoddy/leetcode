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
    map<int, int> store;
    int target;
    bool flag =  false;

    void traversal(TreeNode* root)
    {
        if (root == nullptr) return;

        if (root->val != target - root->val) this->store[root->val] += 1, this->store[target - root->val] += 1;

        if (this->store[root->val] >= 2 && this->store[target - root->val] >= 2) flag = true;

        if (root->left != nullptr) this->traversal(root->left);
        if (root->right != nullptr) this->traversal(root->right);
    }

public:
    bool findTarget(TreeNode* root, int k)
    {
        this->target = k;
        this->traversal(root);
        return this->flag;
    }
};
