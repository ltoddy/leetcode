class Solution
{
public:
    bool lemonadeChange(vector<int>& bills)
    {
//                           5$,10$,15$
        vector<int> money = {0, 0, 0};

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                money[0] += 1;
            } else if (bills[i] == 10) {
                money[1] += 1, money[0] -= 1;
                if (money[0] < 0) return false;
            } else if (bills[i] == 20) {
                if (money[1] > 0) money[1] -= 1, money[0] -= 1;
                else money[0] -= 3;
                if (money[1] < 0 || money[0] < 0) return false;
            }
        }

        return true;
    }
};
