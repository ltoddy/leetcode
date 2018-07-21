class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (size_t i = 0; i < s.length(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};
