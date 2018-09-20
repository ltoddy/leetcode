# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def leaf(self, root):
        res = list()
        if root.left is None and root.right is None: res.append(root.val)
        if root.left is not None: res += self.leaf(root.left)
        if root.right is not None: res += self.leaf(root.right)
        return res

    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        leaf1 = self.leaf(root1)
        leaf2 = self.leaf(root2)
        return leaf1 == leaf2
