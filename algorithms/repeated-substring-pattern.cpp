class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        for (int i = s.length() / 2; i >= 1; i--) {
            if (s.length() % i == 0) {
                int amount = s.length() / i;
                string t = "";
                for (int k = 0; k < amount; k++)
                    t += s.substr(0, i);
                if (t == s) return true;
            }
        }
        return false;
    }
};
