class Solution
{
private:
//    长度32位int,所以打表小于32的素数
    set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    int binaryCount(int n)
    {
        int res = 0;
        while (n > 0) {
            if (n & 1 == 1)
                res++;
            n >>= 1;
        }
        return res;
    }

public:
    int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        for (int i = L; i <= R; i++) {
            if (primes.find(this->binaryCount(i)) != primes.end())
                res++;
        }
        return res;
    }
};
