class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return {};

        auto m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size()); // m rows, n columns

        vector<int> res(static_cast<unsigned long>(m * n));
        int index = 0, left = 0, right = n - 1, up = 0, down = m - 1;
        while (index < m * n) {
            for (int col = left; col <= right; col++) res[index++] = matrix[up][col];
            if (++up > down) break;

            for (int row = up; row <= down; row++) res[index++] = matrix[row][right];
            if (--right < left) break;

            for (int col = right; col >= left; col--) res[index++] = matrix[down][col];
            if (--down < up) break;

            for (int row = down; row >= up; row--) res[index++] = matrix[row][left];
            if (++left > right) break;
        }
        return res;
    }
};
