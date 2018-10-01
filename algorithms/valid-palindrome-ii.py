class Solution:
    @staticmethod
    def is_palindrome(s: str, i: int, j: int) -> bool:
        while i < j:
            if s[i] != s[j]:
                return False
            i, j = i + 1, j - 1
        return True

    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i, j = 0, len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return self.is_palindrome(s, i, j - 1) or self.is_palindrome(s, i + 1, j)
            i, j = i + 1, j - 1
        return True
