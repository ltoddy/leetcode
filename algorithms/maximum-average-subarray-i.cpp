class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        int maxvalue = INT_MIN, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            if (i == k - 1)
                maxvalue = total;
            if (i >= k) {
                total -= nums[i - k];
                maxvalue = max(maxvalue, total);
            }
        }
        return static_cast<double>(maxvalue) / static_cast<double>(k);
    }
};
