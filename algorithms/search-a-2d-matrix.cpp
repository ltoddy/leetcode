class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty()) return false;

        size_t m = matrix.size(), n = matrix[0].size();
        int low = 0, high = static_cast<int>(m * n - 1);

        while (low <= high) {
            int mid = (low + high) / 2;

            if (target < matrix[mid / n][mid % n]) high = mid - 1;
            else if (target > matrix[mid / n][mid % n]) low = mid + 1;
            else if (target == matrix[mid / n][mid % n]) return true;
        }
        return false;
    }
};
