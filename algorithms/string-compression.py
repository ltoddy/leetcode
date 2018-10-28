class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        start, end = 0, 0
        while end < len(chars):
            if chars[start] == chars[end]:
                end += 1
            else:
                if end - start >= 2:
                    chars[start + 1:end] = str(end - start)
                    end = start + 2
                start = end
        if end - start >= 2:
            chars[start + 1:end] = str(end - start)
        return len(chars)
