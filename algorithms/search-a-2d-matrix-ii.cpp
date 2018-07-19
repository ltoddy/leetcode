class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;

        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[row].size(); col++) {
                if (matrix[row][col] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};
