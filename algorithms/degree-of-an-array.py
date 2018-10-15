class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        starts, ends, counts = dict(), dict(), dict()
        mode_count = -1
        for index, num in enumerate(nums):
            if num not in starts:
                starts[num] = index
                counts[num] = 0
            counts[num] += 1
            ends[num] = index
            mode_count = max(mode_count, counts[num])
        shortest = len(nums)
        for num, count in counts.items():
            if count == mode_count:
                shortest = min(shortest, ends[num] - starts[num] + 1)
        return shortest
