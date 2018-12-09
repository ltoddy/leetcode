class Solution
{
public:
    int minDeletionSize(vector<string>& A)
    {
        int result = 0;
        for (int col = 0; col < A[0].length(); col++) {
            for (int row = 0; row < A.size() - 1; row++) {
                if (A[row][col] > A[row + 1][col]) {
                    result += 1;
                    break;
                }
            }
        }
        return result;
    }
};
