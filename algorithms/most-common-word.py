from statistics import mode


class Solution:
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        for dot in r"!?',;.\n":
            paragraph = paragraph.replace(dot, ' ')
        words = filter(lambda word: word not in banned + [' '], map(lambda word: word.lower(), paragraph.split()))
        return mode(words)
