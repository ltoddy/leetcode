class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        map<int, int> store;

        for (int num : nums) {
            if (store[num] > 0) {
                return true;
            } else {
                store[num] = 1;
            }
        }

        return false;
    }
};
