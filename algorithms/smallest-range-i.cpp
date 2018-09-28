class Solution
{
public:
    int smallestRangeI(vector<int>& A, int K)
    {
        int min = INT_MAX, max = INT_MIN;
        for (auto a : A) {
            if (a < min) min = a;
            if (a > max) max = a;
        }
        return max - min > 2 * K ? max - min - 2 * K : 0;
    }
};
