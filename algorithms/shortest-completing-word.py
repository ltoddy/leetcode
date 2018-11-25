from collections import defaultdict


def default_factory():
    return 0


class Solution:
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        words = sorted(words, key=len)
        licensePlate = licensePlate.lower()
        license = defaultdict(default_factory)
        for p in licensePlate:
            if p.isalpha():
                license[p] = license[p] + 1
        for word in words:
            d = defaultdict(default_factory)
            for c in word:
                if c.isalpha():
                    d[c] = d[c] + 1
            flag = True
            for key in license.keys():
                if key not in d.keys() or d[key] < license[key]:
                    flag = False
                    break
            if flag:
                return word
