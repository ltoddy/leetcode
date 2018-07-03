class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.empty()) return 0;

        int len = static_cast<int>(s.length()), cnt = 0;
        for (auto i = len - 1; i >= 0; i--) {
            if (s[i] == ' ') continue;
            while (s[i - cnt] != ' ' && i - cnt >= 0) {
                cnt++;
            }
            return cnt;
        }
        return cnt;
    }
};
