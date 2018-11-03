class Solution
{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int radius = 0;
        for (auto house : houses) {
            int pos = 0;
            while (pos < heaters.size() - 1 && heaters[pos] + heaters[pos + 1] <= house * 2)
                pos++;

            radius = max(radius, abs(heaters[pos] - house));
        }
        return radius;
    }
};
