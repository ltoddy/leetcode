class Solution
{
public:
    int findPairs(vector<int>& nums, int k)
    {
        if (nums.empty()) return 0;

        set<pair<int, int>> diffs;
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (abs(nums[i] - nums[j]) == k) {
                    if (nums[i] > nums[j]) diffs.insert({nums[i], nums[j]});
                    else diffs.insert({nums[j], nums[i]});
                }
        return diffs.size();
    }
};
