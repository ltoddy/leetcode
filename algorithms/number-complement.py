class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        r, m = num, 1
        while r != 1:
            r = r >> 1
            m = (m << 1) + 1
        return num ^ m
