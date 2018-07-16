class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int left = 0, right = static_cast<int>(nums.size() - 1);
        vector<int> res(2, -1);

        while (left <= right) {
            if (nums[left] == target && res[0] == -1) res[0] = left;
            else if (res[0] == -1) left++;

            if (nums[right] == target && res[1] == -1) res[1] = right;
            else if (res[1] == -1) right--;

            if (res[0] != -1 && res[1] != -1) break;
        }
        return res;
    }
};
