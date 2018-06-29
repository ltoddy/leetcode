class Solution
{
public:
    int reverse(int x)
    {
        bool negative = (x < 0);
        x = abs(x);
        long res = 0;
        while (x != 0) {
            res = res * 10 + x % 10;
            x = x / 10;
        }
        res = negative ? -res : res;
        if (res > INT_MAX || res < INT_MIN) {
            return 0;
        }
        return static_cast<int>(res);
    }
};
