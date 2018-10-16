class Solution:
    def is_even(self, num):
        return num % 2 == 0

    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        evens = list(filter(lambda a: a % 2 == 0, A))
        odds = list(filter(lambda a: a % 2 == 1, A))
        result = []
        for i in range(len(A)):
            if self.is_even(i):
                result.append(evens[i // 2])
            else:
                result.append(odds[i // 2])
        return result
