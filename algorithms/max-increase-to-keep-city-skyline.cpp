class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        if (grid.empty()) return 0;

        vector<int> rows = vector<int>(grid.size(), 0);
        vector<int> cols = vector<int>(grid[0].size(), 0);

        for (int i = 0; i < grid.size(); i++) {
            int row_tmp = 0, col_tmp = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] > row_tmp) row_tmp = grid[i][j];
                if (grid[j][i] > col_tmp) col_tmp = grid[j][i];
            }
            rows[i] = row_tmp;
            cols[i] = col_tmp;
        }

        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                result += rows[i] < cols[j] ? (rows[i] - grid[i][j]) : (cols[j] - grid[i][j]);
            }
        }
        return result;
    }
};
