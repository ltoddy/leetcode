class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<pair<size_t, size_t>> coordinates;
        for (size_t row = 0; row < matrix.size(); row++) {
            for (size_t col = 0; col < matrix[row].size(); col++)
                if (matrix[row][col] == 0)
                    coordinates.push_back(make_pair(row, col));
        }

        for (pair<size_t, size_t> coordinate: coordinates) {
            size_t row = coordinate.first, col = coordinate.second;
            for (int& i : matrix[row]) i = 0;
            for (auto& i : matrix) i[col] = 0;
        }
    }
};
