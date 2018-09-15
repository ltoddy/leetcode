from functools import reduce


class Solution:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        if len(ops) == 0: return 0

        stack = list()
        for op in ops:
            if op == '+': stack.append(int(stack[len(stack) - 1]) + int(stack[len(stack) - 2]))
            elif op == 'D': stack.append(int(stack[len(stack) - 1]) * 2)
            elif op == 'C': stack.pop()
            else: stack.append(op)
        return reduce(lambda res, score: res + int(score), stack, 0)
