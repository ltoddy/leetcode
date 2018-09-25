from functools import reduce
from itertools import chain


class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        store = {chr(c): 0 for c in chain(range(ord('a'), ord('z') + 1), range(ord('A'), ord('Z') + 1))}
        for c in s: store[c] += 1
        odd_cnt = len(list(filter(lambda value: value % 2 != 0, store.values())))
        return len(s) - odd_cnt + (0 if odd_cnt == 0 else 1)
