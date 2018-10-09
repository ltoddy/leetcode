class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (s.empty() || p.empty()) return {};

        vector<int> result;

        vector<int> ds = vector<int>(26, 0);
        vector<int> dp = vector<int>(26, 0);
        for(char c : p) dp[c - 'a']++;

        for(int i = 0; i < s.size(); i++) {
            if(i >= p.size()) ds[s[i - p.size()] - 'a']--;
            ds[s[i] - 'a']++;

            if(ds == dp) result.push_back(i - p.size() + 1);
        }
        return result;
    }
};
