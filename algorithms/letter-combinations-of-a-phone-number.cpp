class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};

        vector<string> res;
        map<char, vector<string>> mp;
        mp['2'] = {"a", "b", "c"};
        mp['3'] = {"d", "e", "f"};
        mp['4'] = {"g", "h", "i"};
        mp['5'] = {"j", "k", "l"};
        mp['6'] = {"m", "n", "o"};
        mp['7'] = {"p", "q", "r", "s"};
        mp['8'] = {"t", "u", "v"};
        mp['9'] = {"w", "x", "y", "z"};
        for (auto digit : digits) {
            vector<string> temp;
            auto v = mp[digit];
            for (auto& s:v) {
                for (auto re : res) {
                    string tmp = re + s;
                    temp.push_back(tmp);
                }
                if (res.empty()) temp.push_back(s);
            }
            swap(res, temp);
        }
        return res;
    }
};
