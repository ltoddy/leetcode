class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int diff = INT_MAX;
        int value;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    int cvalue = nums[i] + nums[j] + nums[k];
                    int cdiff = abs(target - cvalue);
                    if (cdiff < diff) {
                        diff = cdiff;
                        value = cvalue;
                    }
                }
            }
        }
        return value;
    }
};
