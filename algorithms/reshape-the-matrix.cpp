class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        if (r * c != nums.size() * nums[0].size()) return nums;

        int index = 0;
        vector<vector<int>> res = vector<vector<int>>(r, vector<int>(c));
        for (int i = 0; i < nums.size() * nums[0].size(); i++) {
            res[i / c][i % c] = nums[i / nums[0].size()][i % nums[0].size()];
        }
        return res;
    }
};
