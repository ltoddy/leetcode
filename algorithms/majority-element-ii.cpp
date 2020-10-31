class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> result;
        map<int, int> count;

        for (auto const num : nums) {
            count[num] += 1;
        }
        for (auto const p : count) {
            if (p.second > nums.size() / 3) {
                result.push_back(p.first);
            }
        }

        return result;
    }
};
