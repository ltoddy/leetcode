# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traversal(self, root):
        if root:
            yield from self.traversal(root.left)
            yield root.val
            yield from self.traversal(root.right)

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        nums = list(self.traversal(root))
        return nums[k - 1]
