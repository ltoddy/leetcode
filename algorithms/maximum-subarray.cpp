class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int maxsum = nums.at(0), tsum = nums.at(0);

        for (auto i = 1; i < nums.size(); i++) {
            tsum = max(tsum + nums[i], nums[i]);

            if (tsum > maxsum) {
                maxsum = tsum;
            }
        }
        return maxsum;
    }
};
