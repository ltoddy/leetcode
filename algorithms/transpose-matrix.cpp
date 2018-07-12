class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>>& A)
    {
        if (A.empty() || A[0].empty()) return {};

        vector<vector<int>> res = vector<vector<int>>(A[0].size(), vector<int>(A.size()));

        for (auto row = 0; row < A.size(); row++) {
            for (auto col = 0; col < A[row].size(); col++)
                res[col][row] = A[row][col];
        }

        return res;
    }
};
