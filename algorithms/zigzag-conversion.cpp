class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1) return s;

        string res;
        for (int i = 0; i < numRows; i++) {
            int pos = i;
            if (pos >= s.length()) break;
            res.push_back(s[pos]);
            for (int j = 0; pos < s.length() && j < s.length(); j++) {
                if (i < numRows - 1) {
                    pos += 2 * (numRows - i - 1);
                    if (pos >= s.length()) break;
                    res.push_back(s[pos]);
                }
                if (i > 0) {
                    pos += i * 2;
                    if (pos >= s.length()) break;
                    res.push_back(s[pos]);
                }
            }
        }
        return res;
    }
};
