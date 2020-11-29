class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlength = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int thissum = 0;
            for (int j = i; j < nums.size(); j++) {
                thissum += nums[j];
                if (thissum >= s) {
                    minlength = min(minlength, j - i + 1);
                    break;
                }
            }
        }
        return minlength == INT_MAX ? 0 : minlength;
    }
};
