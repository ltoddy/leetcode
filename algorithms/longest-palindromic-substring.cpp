class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty() || s.size() == 1) return s;
        int start = 0, longest = 1;
        vector<vector<int> > dp(s.size(), vector<int>(s.size()));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
            if (i < s.size() - 1) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 1;
                    start = i;
                    longest = 2;
                }
            }
        }
        for (int k = 3; k <= s.size(); k++) {
            for (int i = 0; i + k - 1 < s.size(); i++) {
                int end = k + i - 1;
                if (s[i] == s[end] && dp[i + 1][end - 1] == 1) {
                    dp[i][end] = 1;
                    start = i;
                    longest = k;
                }
            }
        }
        return s.substr(start, longest);
    }
};
