class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty()) return 0;

        int cnt = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[cnt]) {
                nums[++cnt] = nums[i];
            }
        }

        nums.resize(static_cast<unsigned long>(cnt + 1));
        return static_cast<int>(nums.size());
    }
};
