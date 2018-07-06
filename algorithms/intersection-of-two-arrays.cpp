class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> res;
        set<int> t = set<int>(nums1.begin(), nums1.end());

        for (auto num : nums2) {
            if (t.count(num)) {
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};
