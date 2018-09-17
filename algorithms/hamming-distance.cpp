class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = 0;
        int z = x ^ y;
        while (z > 0) {
            if (z & 1 == 1) res++;
            z >>= 1;
        }
        return res;
    }
};
