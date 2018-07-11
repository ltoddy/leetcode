class Solution
{
public:
    int findNthDigit(int n)
    {
//                      len     cnt
//        0 - 9         9       1
//        10 - 99       90      2
//        100 - 999     900     3
//        1000 - 9999   9000    4
        long lenOfDigit = 1, count = 9, start = 1;

        while (n > lenOfDigit * count) {
            n -= lenOfDigit * count;
            lenOfDigit += 1;
            count *= 10;
            start *= 10;
        }

        auto num = static_cast<int>(start + (n - 1) / lenOfDigit);
        string s = to_string(num);
        return s[(n - 1) % lenOfDigit] - '0';
    }
};
