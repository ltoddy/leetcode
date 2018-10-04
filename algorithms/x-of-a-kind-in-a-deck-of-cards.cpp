class Solution
{
public:
    bool hasGroupsSizeX(vector<int>& deck)
    {
        vector<int> count = vector<int>(10010, 0);

        for (auto d : deck) count[d] += 1;

        for (int x = 2; x <= 10000; x++) {
            int j = 0;
            for (; j < 10000; j++) {
                if (count[j] % x != 0) break;
            }
            if (j == 10000) return true;
        }
        return false;
    }
};
