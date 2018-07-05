class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        auto res = 0;

        while (n > 0) {
            if (n & 1 == 1)
                res++;
            n >>= 1;
        }

        return res;
    }
};
