class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        string res;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S[i] != '-') {
                if (res.length() % (K + 1) == K) res.push_back('-');
                res.push_back(S[i]);
            }
        }
        reverse(res.begin(), res.end());
        transform(res.begin(), res.end(), res.begin(), ::toupper);
        return res;
    }
};
