class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int res = 0;
        for (auto i = 0; i < prices.size(); i++) {
            for (auto j = i + 1; j < prices.size(); j++)
                if ((prices[j] - prices[i]) > res)
                    res = prices[j] - prices[i];
        }
        return res;
    }
};
