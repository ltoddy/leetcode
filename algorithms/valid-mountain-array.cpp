class Solution
{
public:
    bool validMountainArray(vector<int>& A)
    {
        if (A.size() < 3) return false;

        int crest = 0;
        for (int i = 1; i < A.size(); i++)
            if (A[crest] < A[i]) crest = i;
        if (crest == 0 || crest == A.size() - 1) return false;
        for (int i = crest - 1; i >= 0; i--) {
            if (A[i + 1] <= A[i]) return false;
        }
        for (int i = crest; i < A.size() - 1; i++) {
            if (A[i + 1] >= A[i]) return false;
        }
        return true;
    }
};
