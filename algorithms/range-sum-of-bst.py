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

    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        nums = self.traversal(root)
        result = 0
        for num in nums:
            if num > R:
                break
            if num >= L:
                result += num
        return result
