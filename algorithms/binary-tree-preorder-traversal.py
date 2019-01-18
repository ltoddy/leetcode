# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def traversal(self, root):
        if root is not None:
            yield root.val
            yield from self.traversal(root.left)
            yield from self.traversal(root.right)

    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        return list(self.traversal(root))
