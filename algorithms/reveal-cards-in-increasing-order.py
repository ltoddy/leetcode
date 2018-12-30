class Solution:
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        deck.sort()
        res = [0] * len(deck)
        index = 0
        judge = list(range(len(deck)))
        for i in range(len(res)):
            res[judge[index]] = deck[i]
            judge = judge[:index] + judge[index + 1:]
            index += 1
            if len(judge):
                index %= len(judge)
        return res
