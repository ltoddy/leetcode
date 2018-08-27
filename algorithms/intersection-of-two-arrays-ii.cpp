class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        map<int, int> m;
        for (auto num : nums1) m[num]++;

        vector<int> res;

        for (auto num : nums2) {
            if (m.find(num) != m.end() && m[num] != 0) {
                res.push_back(num);
                m[num]--;
            }
        }
        return res;
    }
};
