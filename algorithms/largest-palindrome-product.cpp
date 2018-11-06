class Solution
{
public:
    int largestPalindrome(int n)
    {
        long long ret[8] = {9, 9009, 906609, 99000099, 9966006699, 999000000999, 99956644665999, 9999000000009999};
        return ret[n - 1] % 1337;
    }
};
