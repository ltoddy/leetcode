class Solution
{
public:
    int distributeCandies(vector<int>& candies)
    {
        map<int, int> kinds;
        for (auto candy : candies) kinds[candy + 100000]++;

        return kinds.size() > candies.size() / 2 ? candies.size() / 2 : kinds.size();
    }
};
