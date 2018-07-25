class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        if (nums.empty()) return;

        vector<long> index;
        long cnt = 0;
        for (long i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                index.push_back(i);
                cnt++;
            }
        }

        for (long i = index.size() - 1; i >= 0; i--)
            nums.erase(nums.begin() + index[i], nums.begin() + index[i] + 1);
        for (long i = 0; i < cnt; i++)
            nums.push_back(0);
    }
};
