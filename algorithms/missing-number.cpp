class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        auto res = static_cast<int>(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i] ^ i;
        }
        return res;
    }
};
