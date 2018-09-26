class Solution
{
private:
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        int area = 1;
        grid[x][y] = 0;

        vector<pair<int, int>> next = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

        for (int k = 0; k < next.size(); k++) {
            int nx = x + next[k].first;
            int ny = y + next[k].second;

            if (nx >= 0 && nx < grid.size() && ny < grid[0].size() && ny >= 0 && grid[nx][ny] == 1) {
                area += this->dfs(grid, nx, ny);
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int res = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == 1) {
                    res = max(this->dfs(grid, row, col), res);
                }
            }
        }
        return res;
    }
};
