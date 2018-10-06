class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split(' ')
        if len(pattern) != len(words) or len(set(pattern)) != len(set(words)):
            return False

        d = dict()
        for index, value in enumerate(pattern):
            if value not in d:
                d[value] = words[index]
            else:
                if d[value] != words[index]:
                    return False

        return True
