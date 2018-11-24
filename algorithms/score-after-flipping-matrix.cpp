class Solution
{
public:
    int matrixScore(vector<vector<int>>& A)
    {
        if (A.empty()) return 0;

        for (int row = 0; row < A.size(); row++) {
            if (A[row][0] == 0)
                for (int col = 0; col < A[row].size(); col++) A[row][col] ^= 1;
        }

        for (int col = 0; col < A[0].size(); col++) {
            int zero = 0, one = 0;
            for (int row = 0; row < A.size(); row++) {
                if (A[row][col] == 0) zero++;
                else one++;
            }

            if (zero > one)
                for (int row = 0; row < A.size(); row++) A[row][col] ^= 1;
        }

        int sum = 0;
        for (int row = 0; row < A.size(); row++) {
            int tmp = 0;
            for (int col = 0; col < A[row].size(); col++)
                tmp = tmp * 2 + A[row][col];
            sum += tmp;
        }
        return sum;
    }
};
