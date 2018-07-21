class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t res = 0;
        for (size_t i = 0; i < 32; i++) {
            res <<= 1;
            if (n & 1 == 1) res ^= 1;
            n >>= 1;
        }
        return res;
    }
};
