class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        vector<pair<int, string>> roman = {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {3,    "III"},
                {2,    "II"},
                {1,    "I"},
        };
        for (int i = 0; i < roman.size() && num > 0; i++) {
            if (num < roman[i].first) continue;
            while (num >= roman[i].first) {
                num -= roman[i].first;
                res += roman[i].second;
            }
        }
        return res;
    }
};
