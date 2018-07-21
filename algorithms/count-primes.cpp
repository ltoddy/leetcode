class Solution
{
private:
    bool isprime(int num)
    {
        for (size_t i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

public:
    int countPrimes(int n)
    {
        vector<bool> nums(static_cast<unsigned long>(n), true);
        nums[0] = false, nums[1] = false;

        for (size_t i = 2; i * i < nums.size(); i++) {
            if (!this->isprime(static_cast<int>(i))) continue;

            for (size_t j = i * i; j < nums.size(); j += i) nums[j] = false;
        }

        return accumulate(nums.begin(), nums.end(), 0,
                          [](int init, bool isprime) -> int { return isprime ? init + 1 : init; });
    }
};
