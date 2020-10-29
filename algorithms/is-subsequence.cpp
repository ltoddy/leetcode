class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }

        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i += 1;
            }
            j += 1;

            if (i == s.length()) {
                return true;
            }
        }

        return false;
    }
};
