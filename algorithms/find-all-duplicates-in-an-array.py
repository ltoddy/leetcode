class Solution:
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        for num in nums:
            num = abs(num)

            if nums[num - 1] > 0:
                nums[num - 1] = - nums[num - 1]
            else:
                result.append(num)
        return result
