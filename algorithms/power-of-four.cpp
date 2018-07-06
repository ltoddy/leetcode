class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0) return false;

        while (num > 0) {
            if ((num & 3) != 0 && num != 1) {
                return false;
            }
            num >>= 2;
        }
        return true;
    }
};
