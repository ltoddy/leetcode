class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int result = 0;
        int record = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            if (diff == 1) {
                record += 1;
            } else if (diff > 1) {
                if (record > result) {
                    result = record;
                }
                record = 1;
            }
        }
        if (record > result) {
            result = record;
        }
        return result;
    }
};
