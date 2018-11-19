class Solution
{
private:
    string revert(string s)
    {
        map<char, int> m;
        for (char c : s)
            if (m.count(c) == 0) m[c] = m.size();

        for (int i = 0; i < s.size(); i++) {
            s[i] = 'a' + m[s[i]];
        }
        return s;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string> result;
        string p = this->revert(pattern);
        for (string word : words) {
            if (this->revert(word) == p) result.push_back(word);
        }
        return result;
    }
};
