class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int maxvalue = 0, prevalue = 0;
        for (auto num : nums) {
            int tmp = maxvalue;
            maxvalue = max(maxvalue, prevalue + num);
            prevalue = tmp;
        }
        return maxvalue;
    }
};
