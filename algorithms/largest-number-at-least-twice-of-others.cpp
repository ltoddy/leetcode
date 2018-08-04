class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        if (nums.empty()) return -1;

        int max = INT_MIN, index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }
        for (auto num: nums) {
            if (num * 2 > max && num != max) {
                index = -1;
                break;
            }
        }

        return index;
    }
};
