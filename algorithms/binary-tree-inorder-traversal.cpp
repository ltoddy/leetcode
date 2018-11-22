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
    vector<int> result;

    void traversal(TreeNode* root)
    {
        if (root != nullptr) {
            inorderTraversal(root->left);
            this->result.push_back(root->val);
            inorderTraversal(root->right);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        this->traversal(root);
        return this->result;
    }
};

|94|[二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/)|中等|[已解决](binary-tree-inorder-traversal.cpp)|
