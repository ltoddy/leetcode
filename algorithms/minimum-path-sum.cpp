class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

        dp[0][0] = grid[0][0];
        for (int row = 1; row < grid.size(); row++) dp[row][0] = dp[row - 1][0] + grid[row][0];
        for (int col = 1; col < grid[0].size(); col++) dp[0][col] = dp[0][col - 1] + grid[0][col];

        for (int row = 1; row < grid.size(); row++)
            for (int col = 1; col < grid[row].size(); col++)
                dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];

        return dp[grid.size() - 1][grid[grid.size() - 1].size() - 1];
    }
};
