class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        vector<int> res;
        for (int i = 0; i < findNums.size(); i++) {
            bool flag = false;
            for (int j = 0; j < nums.size(); j++) {
                if (findNums[i] == nums[j]) flag = true;
                if (flag && findNums[i] < nums[j]) {
                    res.push_back(nums[j]);
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(-1);
        }
        return res;
    }
};
