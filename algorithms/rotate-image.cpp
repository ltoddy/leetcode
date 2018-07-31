class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        for (int row = 0; row < matrix.size(); row++) {
            for (int col = row + 1; col < matrix[row].size(); col++)
                swap(matrix[row][col], matrix[col][row]);
        }

        for (int row = 0; row < matrix.size(); row++) {
            for (int col = 0; col < matrix[row].size() / 2; col++)
                swap(matrix[row][col], matrix[row][matrix[row].size() - col - 1]);
        }
    }
};
