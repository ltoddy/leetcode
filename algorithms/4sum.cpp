class Solution {
private:
    set<vector<int>> result;
    map<int, int> hash;

    void combine(vector<int> &nums, int n, vector<int> &store, int m, int target) {
        for (int i = n; i >= m; i--) {
            store[m - 1] = nums[i - 1];
            if (m > 1) {
                this->combine(nums, i - 1, store, m - 1, target);
            } else {
                this->hash[store[0]] -= 1, this->hash[store[1]] -= 1, this->hash[store[2]] -= 1;

                int diff = target - accumulate(store.begin(), store.end(), 0);
                if (this->hash[diff] >= 1) {
                    vector<int> value = vector<int>(store.begin(), store.end());
                    value.push_back(diff);
                    sort(value.begin(), value.end());
                    this->result.insert(value);
                }

                this->hash[store[0]] += 1, this->hash[store[1]] += 1, this->hash[store[2]] += 1;
            }
        }
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        for (auto num: nums) {
            this->hash[num] += 1;
        }

        vector<int> store(3);
        this->combine(nums, nums.size(), store, 3, target);
        return vector<vector<int>>(this->result.begin(), this->result.end());
    }
};
