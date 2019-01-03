# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traversal(self, root):
        if root is not None:
            yield from self.traversal(root.left)
            yield root.val
            yield from self.traversal(root.right)

    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        values = self.traversal(root)
        cur = next(values)
        for val in values:
            if val != cur:
                return False
        return True
