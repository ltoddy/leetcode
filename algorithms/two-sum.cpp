class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i]) == 0) {
                m[target - nums[i]] = i;
            } else {
                result.push_back(m.at(nums[i]));
                result.push_back(i);
                return result;
            }
        }
    }
};
