class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        if (s.length() <= 1) return 0;

        int result = 0, pre = 0, cur = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                cur++;
            } else {
                result += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return result + min(cur, pre);
    }
};
