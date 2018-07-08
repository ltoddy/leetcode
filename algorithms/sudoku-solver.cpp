class Solution
{
private:
    bool canplace(vector<vector<char>>& board, int row, int col, char num)
    {
        // 数字num是否可以放置在(row, col)处
        for (int i = 0; i < 9; i++)
            if (board[row][i] == num || board[i][col] == num)
                return false;

        int r = row / 3 * 3, c = col / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                if (board[r + i][c + j] == num)
                    return false;
        }
        return true;
    }

    bool dfs(vector<vector<char>>& board, int row, int col)
    {
        if (row == 9) return true;
        if (col == 9) return dfs(board, row + 1, 0);
        if (board[row][col] != '.') return dfs(board, row, col + 1);

        for (char num = '1'; num <= '9'; num++) {
            if (canplace(board, row, col, num)) {
                board[row][col] = num;
                if (dfs(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board)
    {
        dfs(board, 0, 0);
    }
};
