class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> bucket(nums.size() + 1);
        vector<int> res;

        for (auto num: nums)
            bucket[num]++;

        for (auto i = 1; i < bucket.size(); i++) {
            if (bucket[i] == 0)
                res.push_back(i);
        }

        return res;
    }
};
