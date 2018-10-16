class Solution
{
private:
    inline int average(vector<int> nums)
    {
        return accumulate(nums.begin(), nums.end(), 0, [](int a, int b) -> int { return a + b; }) / nums.size();
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M)
    {
        if (M.empty()) return {};

        vector<pair<int, int>> next = {{1, 0}, {0, 1},{-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        vector<vector<int>> result = vector<vector<int>>(M.size(), vector<int>(M[0].size()));
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[i].size(); j++) {
                vector<int> nums = {M[i][j]};
                for (int k = 0; k < next.size(); k++) {
                    int x = i + next[k].first;
                    int y = j + next[k].second;
                    if (x >= 0 && x < M.size() && y >= 0 && y < M[i].size()) nums.push_back(M[x][y]);
                }
                result[i][j] = this->average(nums);
            }
        }
        return result;
    }
};
