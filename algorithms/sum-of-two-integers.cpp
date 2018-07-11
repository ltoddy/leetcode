class Solution
{
public:
    int getSum(int a, int b)
    {
        while (a != 0) {
            int tmp = (a & b) << 1;
            b = a ^ b;
            a = tmp;
        }
        return b;
    }
};
