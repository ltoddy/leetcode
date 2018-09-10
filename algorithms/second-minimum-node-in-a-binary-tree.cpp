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
    map<int, int> count;

    void through(TreeNode* root)
    {
        if (root == nullptr) return;

        this->count[root->val] += 1;
        if (root->left != nullptr) this->through(root->left);
        if (root->right != nullptr) this->through(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode* root)
    {
        this->through(root);
        if (this->count.size() == 1) return -1;
        map<int, int>::iterator it = this->count.begin();
        it++;
        return it->first;
    }
};
