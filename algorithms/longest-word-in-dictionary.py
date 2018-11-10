class Solution:
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        res = ""
        words = set(words)
        for word in words:
            if len(word) > len(res) or len(word) == len(res) and word < res:
                if all(word[:k] in words for k in range(1, len(word))):
                    res = word
        return res
