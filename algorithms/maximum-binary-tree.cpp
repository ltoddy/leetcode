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
    vector<int> nums;

    TreeNode* constructMaximumBinaryTree(int left, int right)
    {
        if (left > right) return nullptr;

        int index = left, current = nums[left];
        for (int i = left; i <= right; i++) {
            if (nums[i] > current) {
                current = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(nums[index]);
        root->left = this->constructMaximumBinaryTree(left, index - 1);
        root->right = this->constructMaximumBinaryTree(index + 1, right);
        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        if (nums.empty()) return nullptr;

        this->nums = nums;
        TreeNode* root = this->constructMaximumBinaryTree(0, nums.size() - 1);
        return root;
    }
};
