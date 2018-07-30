class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) continue;
            else if (nums[i] == i + 1 || nums[i] > nums.size()) continue;
            else {
                swap(nums[i], nums[nums[i] - 1]);
                if (nums[i] != i + 1) {
                    if (nums[nums[i] - 1] == nums[i]) continue;
                    else i--;
                }
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return static_cast<int>(nums.size() + 1);
    }
};
