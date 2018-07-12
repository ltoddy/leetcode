class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        if (c < 0) return false;

        int mid = static_cast<int>(sqrt(c));
        int left = 0, right = mid;
        while (left <= right) {
            int tmp = left * left + right * right;
            if (tmp == c) return true;
            else if (tmp > c) right--;
            else if (tmp < c) left++;
        }
        return false;
    }
};
