class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n > 0) {
            res += n / 5;
            n = n / 5;
        }
        return res;
    }
};
