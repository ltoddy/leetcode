class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1) return false;

        vector<int> factors = {1};
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                factors.push_back(i);
                factors.push_back(num / i);
            }
        }
        return num == accumulate(factors.begin(), factors.end(),
                                 0,
                                 [](int init, int factor) -> int { return init + factor; });
    }
};
