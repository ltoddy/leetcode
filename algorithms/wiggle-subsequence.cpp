class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int length = 1;
        int prev = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            if ((diff < 0 && prev >= 0) || (diff > 0 && prev <= 0)) {
                length += 1;
                prev = diff;
            }
        }
        return length;
    }
};
