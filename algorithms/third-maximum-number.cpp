class Solution
{
public:
    int thirdMax(vector<int>& nums)
    {
        long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;

        for (int num : nums) {
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num < max1 && num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num < max2 && num > max3) {
                max3 = num;
            }
        }
        return static_cast<int>(max3 == LONG_MIN ? max1 : max3);
    }
};
