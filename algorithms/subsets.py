class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = [[]]
        for num in nums:
            for tmp in result[:]:
                x = tmp[:]
                x.append(num)
                result.append(x)
        return result
