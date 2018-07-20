class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0) return 1.0;

        double half = this->myPow(x, n / 2);

        if (n % 2 == 0) return half * half;
        else if (n % 2 == 1) return half * half * x;
        else return half / x * half;
    }
};
