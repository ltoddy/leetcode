class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if (flowerbed.empty()) return false;
        if (n <= 0) return true;

        int count = 1;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) count++;
            else n -= (count - 1) / 2, count = 0;
        }
        if (count != 0) n -= count / 2;
        return n <= 0;
    }
};
