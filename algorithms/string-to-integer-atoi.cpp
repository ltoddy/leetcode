class Solution
{
public:
    int myAtoi(string str)
    {
        unsigned long res = 0;

        str.erase(0, str.find_first_not_of(' '));
        str.erase(str.find_last_not_of(' ') + 1); // trim space
        if (!(str[0] == '-' || str[0] == '+' || isdigit(str[0]))) {
            return 0;
        }

        bool neg = false;
        if (str[0] == '-') {
            neg = true;
            str.erase(str.begin(), str.begin() + 1);
        } else if (str[0] == '+') {
            neg = false;
            str.erase(str.begin(), str.begin() + 1);
        }
        str.erase(0, str.find_first_not_of('0')); // remove the beginning of zero

        size_t cnt = 0;
        for (char c : str) {
            if (isdigit(c)) {
                cnt++;
                if (cnt > 10) return neg ? INT_MIN : INT_MAX; // out of int type bound
                res = res * 10 + c - '0';
            } else {
                break;
            }
        }

        if (res > INT_MAX) return neg ? INT_MIN : INT_MAX;
        return static_cast<int>(neg ? -res : res);
    }
};
