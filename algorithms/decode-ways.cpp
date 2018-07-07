class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.empty() || (s.length() >= 1 && s[0] == '0')) return 0;

        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;

        for (auto i = 1; i < dp.size(); i++) {
            dp[i] = (s[i - 1] == '0') ? 0 : dp[i - 1];
            if (i >= 2 && ((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
