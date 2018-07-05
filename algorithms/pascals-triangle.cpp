class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> res;
        res.push_back(vector<int>{1});

        res.push_back(vector<int>{1, 1});

        for (auto i = 2; i < numRows; i++) {
            int numCols = i + 1;
            vector<int> row(static_cast<unsigned long>(numCols));
            row[0] = 1, row[numCols - 1] = 1;
            for (auto j = 1; j < numCols - 1; j++) {
                row[j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};
