# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def _traversal(self, root):
        if root is not None:
            yield from self._traversal(root.left)
            yield from self._traversal(root.right)
            yield root.val

    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        return list(self._traversal(root))
