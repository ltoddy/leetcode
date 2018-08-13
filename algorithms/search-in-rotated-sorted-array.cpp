#define val(x) (x < nums[0] ? x + 0xfffff : x)

class Solution
{
public:

    int search(vector<int>& nums, int target)
    {
        if (nums.empty()) return -1;

        int left = 0, right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (val(nums[mid]) > val(target)) right = mid - 1;
            else if (val(nums[mid]) < val(target)) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};
