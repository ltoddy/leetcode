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
    vector<string> res;

    void traversal(TreeNode* node, string path)
    {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr) {
            this->res.push_back(path + to_string(node->val));
        } else {
            this->traversal(node->left, path + to_string(node->val) + "->");
            this->traversal(node->right, path + to_string(node->val) + "->");
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        traversal(root, "");
        return this->res;
    }
};
