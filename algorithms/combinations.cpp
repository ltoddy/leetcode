class Solution {
private:
    vector<vector<int>> result;

    void dfs(int n, int k, vector<int> tmp)
    {
        if (tmp.size() == k) {
            this->result.push_back(tmp);
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!tmp.empty() && i <= tmp.back())
                continue;
            tmp.push_back(i);
            dfs(n, k, tmp);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> tmp;
        dfs(n, k, tmp);
        return this->result;
    }
};
