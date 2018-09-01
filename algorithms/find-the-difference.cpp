class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        vector<int> alpha = vector<int>(26, 0);

        for (char c : s) alpha[c - 'a']++;

        for (char c : t) alpha[c - 'a']--;

        for (int i = 0; i < alpha.size(); i++) {
            if (alpha[i] < 0) return 'a' + i;
        }
    }
};
