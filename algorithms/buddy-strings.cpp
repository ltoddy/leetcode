class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length()) return false;

        if (A == B) {
            for (int i = 0; i < A.length(); i++) {
                if (A.find(A[i]) != i) return true;
            }
            return false;
        } else {
            vector<int> diffs;
            for (int i = 0; i < A.length(); i++) {
                if (A[i] != B[i]) diffs.push_back(i);
            }
            if (diffs.size() == 2) {
                swap(A[diffs[0]], A[diffs[1]]);
                return A == B;
            } else {
                return false;
            }
        }
    }
};
