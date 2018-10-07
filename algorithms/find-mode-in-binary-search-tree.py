from collections import Counter


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []

        def traversal(node):
            if node:
                yield from traversal(node.left)
                yield node.val
                yield from traversal(node.right)

        modes = []
        frequent = 0

        for value, freq in Counter(list(traversal(root))).most_common():
            if not modes:
                modes.append(value)
                frequent = freq
            else:
                if freq >= frequent:
                    modes.append(value)

        return modes
