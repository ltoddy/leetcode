class Solution:
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        order = {alpha: index for index, alpha in enumerate(order)}
        for i in range(len(words) - 1):
            flag = True
            for j in range(min(len(words[i]), len(words[i + 1]))):
                if order[words[i][j]] < order[words[i + 1][j]]:
                    flag = False
                    break
                elif order[words[i][j]] > order[words[i + 1][j]]:
                    return False
            if flag and len(words[i]) > len(words[i + 1]):
                return False
        return True
