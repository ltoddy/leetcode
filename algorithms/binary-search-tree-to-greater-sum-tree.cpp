/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	int sum = 0;

	void dfs(TreeNode* root) {
		if (root->right != nullptr) {
			this->dfs(root->right);
		}
		this->sum += root->val;
		root->val = this->sum;
		if (root->left != nullptr) {
			this->dfs(root->left);
		}
	}

public:
    TreeNode* bstToGst(TreeNode* root) {
		this->dfs(root);
		return root;
    }
};
