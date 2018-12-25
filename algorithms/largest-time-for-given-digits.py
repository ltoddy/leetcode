from itertools import permutations


class Solution:
    def validate(self, time):
        h1, h2, m1, m2 = time
        return "00" <= f"{h1}{h2}" < "24" and "00" <= f"{m1}{m2}" < "60"

    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        times = list(filter(self.validate, permutations(A)))
        if len(times) == 0: return ""

        best = max(times)
        return f"{best[0]}{best[1]}:{best[2]}{best[3]}"
