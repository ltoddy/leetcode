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
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = this->sortedArrayToBST(nums, left, mid - 1);
        node->right = this->sortedArrayToBST(nums, mid + 1, right);
        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.empty()) return nullptr;

        return this->sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
