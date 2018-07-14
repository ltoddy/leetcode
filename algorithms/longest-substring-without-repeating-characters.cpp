class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        int left = 0; // left: 无重复子串左下标
        int alpha[256] = {0}; // alpha[256]统计出现的字母,即字母最后出现的地方. e.g.: "abcdab" alpha['b'] = 5;

        for (int i = 0; i < s.length(); i++) {
            if (alpha[s[i]] == 0 || alpha[s[i]] < left) {
                res = max(res, i - left + 1);
            } else {
                left = alpha[s[i]];
            }
            alpha[s[i]] = i + 1;
        }

        return res;
    }
};
