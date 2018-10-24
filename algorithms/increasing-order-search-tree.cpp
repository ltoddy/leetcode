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
    vector<int> data;

    void traversal(TreeNode* node)
    {
        if (node != nullptr) {
            traversal(node->left);
            this->data.push_back(node->val);
            traversal(node->right);
        }
    }

public:
    TreeNode* increasingBST(TreeNode* root)
    {
        if (root == nullptr) return nullptr;

        this->traversal(root);
        TreeNode* head = new TreeNode(this->data[0]);
        TreeNode* tmp = head;

        for (int i = 1; i < this->data.size(); i++) {
            TreeNode* node = new TreeNode(this->data[i]);
            tmp->right = node;
            tmp = tmp->right;
        }
        return head;
    }
};
