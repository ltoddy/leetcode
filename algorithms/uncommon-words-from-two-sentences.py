class Solution:
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        words = dict()

        for word in A.split() + B.split():
            words[word] = words.get(word, 0) + 1

        result = []
        for word, count in words.items():
            if count == 1:
                result.append(word)
        return result
