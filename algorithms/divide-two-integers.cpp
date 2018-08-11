class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;

        bool negative = dividend < 0 ^divisor < 0;
        long m = abs(static_cast<long>(dividend)), n = abs(static_cast<long>(divisor));
        if (n == 1) return negative ? -m : m;

        int res = 0;
        while (m >= n) {
            m -= n;
            res++;
        }
        return negative ? -res : res;
    }
};
