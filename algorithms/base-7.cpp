class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0) return "0";
        bool negative = num < 0;
        num = abs(num);
        string res;
        while (num > 0) {
            res.push_back(static_cast<char>(num % 7 + '0'));
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return negative ? "-" + res : res;
    }
};
