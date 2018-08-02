class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        vector<vector<int>> res(A.size(), vector<int>(A[0].size()));
        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A[row].size(); col++) {
                res[row][col] = A[row][A[row].size() - 1 - col];
            }
        }

        for (int row = 0; row < A.size(); row++) {
            for (int col = 0; col < A.size(); col++) {
                res[row][col] ^= 1;
            }
        }

        return res;
    }
};
