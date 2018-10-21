from functools import reduce


class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums: return 0

        min_ = min(nums)
        sum = reduce(lambda s, n: s + n, nums, 0)
        return sum - len(nums) * min_
