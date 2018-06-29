class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }

        int t = x, reverse = 0;
        while (t != 0) {
            reverse = reverse * 10 + t % 10;
            t = t / 10;
        }
        return reverse == x;
    }
};
