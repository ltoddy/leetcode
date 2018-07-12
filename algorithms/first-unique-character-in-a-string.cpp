class Solution
{
public:
    int firstUniqChar(string s)
    {
        for (auto i = 0; i < s.size(); i++) {
            bool unique = true;
            for (auto j = 0; j < s.size(); j++)
                if (s[i] == s[j] && i != j) {
                    unique = false;
                    break;
                }

            if (unique) return i;
        }
        return -1;
    }
};
