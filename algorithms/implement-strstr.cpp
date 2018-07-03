class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return static_cast<int>(haystack.find(needle));
    }
};
