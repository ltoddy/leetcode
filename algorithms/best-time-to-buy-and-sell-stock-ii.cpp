class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) return 0;

        int count = 0, k;
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] - prices[i] > 0) count += prices[i + 1] - prices[i];
        }
        return count;
    }
};
