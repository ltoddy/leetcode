class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty()) return "";

        if (strs.size() == 1) return strs[0];

        for (size_t i = 0; i < strs[0].size(); i++) {
            for (size_t j = 1; j < strs.size(); j++) {
                if ((i > strs[j].length()) || (strs[j][i] != strs[0][i])) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
