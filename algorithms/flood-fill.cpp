class Solution
{
private:
    const vector<pair<int, int>> next = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<int>>& image, int r, int c, int newColor, int oldColor, vector<vector<bool>>& book)
    {
        if (image[r][c] == oldColor) {
            image[r][c] = newColor;
            book[r][c] = true;
            for (int k = 0; k < this->next.size(); k++) {
                int nr = r + next[k].first, nc = c + next[k].second;
                if (nr >= 0 && nr < image.size() && nc >= 0 && nc <= image[0].size() && !book[nr][nc]) {
                    this->dfs(image, nr, nc, newColor, oldColor, book);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        vector<vector<bool>> book = vector<vector<bool>>(image.size(), vector<bool>(image[0].size(), false));
        this->dfs(image, sr, sc, newColor, oldColor, book);
        return image;
    }
};
