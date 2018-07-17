// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1, right = n;
        while (left <= right) {
            int target = (right - left) / 2 + left, res = guess(target);

            if (res == 0) return target;
            else res == -1 ? right = target - 1 : left = target + 1;
        }
        return -1;
    }
};
