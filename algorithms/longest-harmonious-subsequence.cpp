class Solution
{
public:
    int findLHS(vector<int>& nums)
    {
        map<int, int> m;
        for (auto num : nums) m[num]++;

        int len = 0;
        for (auto it : m) {
            if (m.find(it.first + 1) != m.end())
                len = max(len, m[it.first] + m[it.first + 1]);
        }
        return len;
    }
};
