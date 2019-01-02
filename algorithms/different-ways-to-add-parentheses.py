class Solution:
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        result = []
        for i in range(len(input)):
            if input[i] == '+' or input[i] == '-' or input[i] == '*':
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i+1:])
                for j in range(len(left)):
                    for k in range(len(right)):
                        if input[i] == '+':
                            result.append(left[j] + right[k])
                        elif input[i] == '-':
                            result.append(left[j] - right[k])
                        else:
                            result.append(left[j] * right[k])

        if len(result) == 0:
            result.append(eval(input))
        return sorted(result)
