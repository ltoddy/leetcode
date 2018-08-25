class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int max = 0, cnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) cnt++;
            else if (nums[i] == 0) cnt = 0;

            if (max < cnt) max = cnt;
        }

        return max;
    }
};
