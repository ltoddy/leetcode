from math import ceil


class Solution:
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        units = 0
        for c in S:
            width = widths[ord(c) - ord('a')]
            units = ceil(units / 100.0) * 100 + width if 100 - units % 100 < width else units + width
        return [ceil(units / 100), units % 100]
