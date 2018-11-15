class Solution
{
private:
    int calc(int num)
    {
        int cnt = 0;
        while (num > 0) {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }

public:
    vector<int> countBits(int num)
    {
        vector<int> result;
        for (int i = 0; i <= num; i++)
            result.push_back(this->calc(i));
        return result;
    }
};
