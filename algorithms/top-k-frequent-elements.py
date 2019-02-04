from collections import Counter
from operator import itemgetter


class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        return list(map(itemgetter(0), Counter(nums).most_common(k)))
