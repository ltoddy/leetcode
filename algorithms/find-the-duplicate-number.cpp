class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int left = 1, right = static_cast<int>(nums.size() - 1);
        while (left < right) {
            int mid = (left + right) / 2;
            int count = 0;
            for (int num: nums)
                if (num <= mid) count++;

            if (count > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
