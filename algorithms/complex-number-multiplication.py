class Solution:
    def complexNumberMultiply(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        # (a + bi) * (c + di) = ac - bd + (bc + ad)i
        c, d = b.split('+')
        a, b = a.split('+')
        a, b, c, d = int(a), int(b[:-1]), int(c), int(d[:-1])
        return "{}+{}i".format(a * c - b * d, (b * c + a * d))
