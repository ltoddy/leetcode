class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        if (nums.empty() || k % nums.size() == 0) return;

        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
