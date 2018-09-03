class Solution
{
public:
    int arrangeCoins(int n)
    {
        int res = 0;
        for (int i = 1; ; i++) {
            n = n - i;
            if (n >= 0) res++;
            else break;
        }
        return res;
    }
};
