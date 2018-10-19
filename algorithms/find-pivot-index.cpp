class Solution
{
public:
    int pivotIndex(vector<int>& nums)
    {
        if (nums.empty()) return -1;
        int pivot = -1;
        for (int i = 0; i < nums.size(); i++) {
            int left_sum = 0, right_sum = 0;
            for (int j = 0; j < i; j++) left_sum += nums[j];
            for (int j = i + 1; j < nums.size(); j++) right_sum += nums[j];
            if (left_sum == right_sum) {
                pivot = i;
                break;
            }
        }
        return pivot;
    }
};
