class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int begin = -1, end = -1;
        for (int i = 0; i < copy.size(); i++) {
            if (copy[i] != nums[i] && begin == -1) begin = i;
            if (copy[i] != nums[i] && begin != -1) end = i;
        }

        if (begin == -1 && end == -1) return 0;
        else return end - begin + 1;
    }
};
