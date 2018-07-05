class Solution
{
public:
    int titleToNumber(string s)
    {
        if (s.empty()) return 0;

        int res = 0, cnt = 0;
        for (auto i = static_cast<int>(s.length() - 1); i >= 0; i--) {
            res += (s[i] - 'A' + 1) * pow(26, cnt);
            cnt++;
        }
        return res;
    }
};
