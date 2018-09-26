class Solution
{
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int blocks = 0, neighbours = 0;

        vector<pair<int, int>> next = {{0, 1}, {1, 0}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    blocks++;
                    for (int k = 0; k < next.size(); k++) {
                        int nx = i + next[k].first, ny = j + next[k].second;
                        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[i].size() && grid[nx][ny] == 1) neighbours++;
                    }
                }
            }
        }

        return blocks * 4 - neighbours * 2;
    }
};
