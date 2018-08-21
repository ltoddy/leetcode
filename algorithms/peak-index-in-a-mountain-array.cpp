class Solution
{
public:
    int peakIndexInMountainArray(vector<int>& A)
    {
        if (A.size() < 3) return -1;

        int index = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
                index = i;
                break;
            }
        }
        return index;
    }
};
