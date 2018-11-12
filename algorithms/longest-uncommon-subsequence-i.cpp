class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        return a.length() != b.length() ? max(a.length(), b.length()) : a == b ? -1 : a.length();
    }
};
