class Solution
{
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        if (nums[nums.size() - 1] < 0)
            return accumulate(nums.end() - 3, nums.end(), 1, [](int init, int e) -> int { return init * e; });

        return max(nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3],
                   nums[nums.size() - 1] * nums[0] * nums[1]);
    }
};
