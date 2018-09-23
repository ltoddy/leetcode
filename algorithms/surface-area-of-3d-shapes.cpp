class Solution
{
public:
    int surfaceArea(vector<vector<int>>& grid)
    {
        int area = 0;
        int N = grid.size();

        for (int i = 0; i < N; ++i) {
            area += grid[i][0];
            area += grid[0][i];
            area += grid[i][0] ? 2 : 0;

            for (int j = 1; j < N; ++j) {
                area += abs(grid[i][j] - grid[i][j - 1]);
                area += abs(grid[j][i] - grid[j - 1][i]);
                area += grid[i][j] ? 2 : 0;
            }

            area += grid[i][N - 1];
            area += grid[N - 1][i];
        }

        return area;
    }
};
