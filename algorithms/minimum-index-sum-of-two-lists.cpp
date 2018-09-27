class Solution
{
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        priority_queue<pair<int, vector<string>>, std::vector<pair<int, vector<string>>>, std::greater<pair<int, vector<string>>>> pque;

        for (int t = 0; t <= list1.size() + list2.size() - 2; t++) {
            vector<string> tmp;
            for (int i = 0; i <= t; i++) {
                int j = t - i;
                if (i < list1.size() && j < list2.size() && list1[i] == list2[j]) {
                    tmp.push_back(list1[i]);
                }
            }
            if (!tmp.empty()) pque.push({t, tmp});
        }

        return pque.top().second;
    }
};
