class Solution
{
private:
    bool check(int n)
    {
        int tmp = n;
        while (n > 0) {
            int d = n % 10;
            if (d == 0 || tmp % d != 0)
                return false;
            n /= 10;
        }
        return true;
    }

public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        if (left > right) return {};

        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (this->check(i))
                res.push_back(i);
        }
        return res;
    }
};
