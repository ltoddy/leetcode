class Solution {
private:
    void dfs(int step, vector<int> &charset, vector<int> &store, vector<bool> &book, set<vector<int>> &s) {
        if (step == charset.size()) {
            s.insert(store);
            return;
        }

        for (int i = 0; i < charset.size(); i++) {
            if (!book[i]) {
                store[step] = charset[i];
                book[i] = true;
                this->dfs(step + 1, charset, store, book, s);
                book[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<int> store = vector<int>(nums.size());
        vector<bool> book = vector<bool>(nums.size());
        set<vector<int>> s;
        this->dfs(0, nums, store, book, s);
        vector<vector<int>> result;
        for (const auto &sub : s) {
            result.push_back(sub);
        }
        return result;
    }
};
