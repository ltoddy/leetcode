class Solution
{
public:
    int addDigits(int num)
    {
        while (num >= 10) {
            int tmp = num, cnt = 0;
            while (tmp > 0)
                cnt += tmp % 10, tmp /= 10;
            num = cnt;
        }
        return num;
    }
};
