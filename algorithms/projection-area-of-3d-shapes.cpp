class Solution
{
public:
    int projectionArea(vector<vector<int>>& grid)
    {
        if (grid.empty()) return 0;

        int area = 0;
        vector<int> rows, columns;
        for (int row = 0; row < grid.size(); row++) {
            int current_row_max = 0, current_column_max = 0;
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] > current_row_max) current_row_max = grid[row][col];
                if (grid[col][row] > current_column_max) current_column_max = grid[col][row];
                if (grid[row][col] > 0) area++;
            }
            rows.push_back(current_row_max);
            columns.push_back(current_column_max);
        }
        return area + accumulate(rows.begin(), rows.end(), 0, [](int a, int b) -> int { return a + b; })
                    + accumulate(columns.begin(), columns.end(), 0, [](int a, int b) -> int { return a + b; });
    }
};
