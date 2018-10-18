class Solution
{
public:
    bool isMonotonic(vector<int>& A)
    {
        if (A.size() <= 1) return true;

        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1]) dec = false;
            if (A[i] < A[i - 1]) inc = false;
        }
        return inc || dec;
    }
};
