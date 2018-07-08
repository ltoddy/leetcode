class Solution
{
    void dfs(vector<vector<int>>& res, vector<int> nums, vector<int> store, vector<bool>& book, int step)
    {
        if (step == nums.size()) {
            res.push_back(store);
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (!book[i]) {
                store[step] = nums[i];
                book[i] = true;
                dfs(res, nums, store, book, step + 1);
                book[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        if (nums.empty()) return vector<vector<int>>();

        vector<vector<int>> res;
        vector<bool> book(nums.size(), false);
        vector<int> store(nums.size(), 0);
        dfs(res, nums, store, book, 0);
        return res;
    }
};
