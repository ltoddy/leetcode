class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int maxl = 1;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = 1;
            for (int j = i; j < nums.size() - 1; j++) {
                if (nums[j] < nums[j + 1]) tmp++, maxl = tmp > maxl ? tmp : maxl;
                else break;
            }
        }
        return maxl;
    }
};
