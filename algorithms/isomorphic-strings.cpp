class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int ms[256] = {0}, mt[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            if (ms[s[i]] != mt[t[i]]) return false;

            ms[s[i]] = i + 1;
            mt[t[i]] = i + 1;
        }

        return true;
    }
};
