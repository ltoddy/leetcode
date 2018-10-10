class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        words = S.split(' ')

        for i in range(len(words)):
            if words[i].startswith('a') or words[i].startswith('e') or words[i].startswith('i') or words[i].startswith('o') or words[i].startswith('u') or \
               words[i].startswith('A') or words[i].startswith('E') or words[i].startswith('I') or words[i].startswith('O') or words[i].startswith('U'):
                words[i] = words[i] + 'ma' + (i + 1) * 'a'
            else:
                words[i] = words[i][1:] + words[i][0] + 'ma' + (i + 1) * 'a'

        return ' '.join(words)
