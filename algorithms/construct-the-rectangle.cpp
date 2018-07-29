class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        if (area == (static_cast<int>(sqrt(area)) * static_cast<int>(sqrt(area))))
            return {static_cast<int>(sqrt(area)), static_cast<int>(sqrt(area))};

        vector<int> factors;
        for (int i = 1; i <= area; i++) {
            if (area % i == 0)
                factors.push_back(i);
        }
        return {factors[factors.size() / 2], factors[factors.size() / 2 - 1]};
    }
};
