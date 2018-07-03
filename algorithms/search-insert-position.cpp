class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        if (nums.empty()) return 0;

        int low = 0, high = static_cast<int>(nums.size() - 1);

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }

        return low;
    }
};
