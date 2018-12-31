class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        stack = list()
        for parenthesis in S:
            if len(stack) > 0 and parenthesis == ')' and stack[-1] == '(':
                stack.pop(-1)
            else:
                stack.append(parenthesis)
        return len(stack)
