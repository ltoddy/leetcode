class Solution
{
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B)
    {
        int sum_A = accumulate(A.begin(), A.end(), 0, [](int a, int b) -> int { return a + b; });
        int sum_B = accumulate(B.begin(), B.end(), 0, [](int a, int b) -> int { return a + b; });

        int diff = (sum_A - sum_B) / 2;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] - B[j] == diff) return {A[i], B[j]};
            }
        }
    }
};
