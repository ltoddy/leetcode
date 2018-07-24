class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        if (cost.size() == 2) return min(cost[0], cost[1]);

        vector<int> dp(cost.size() + 1);
        dp[0] = 0, dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }
        return dp[cost.size()];
    }
};
