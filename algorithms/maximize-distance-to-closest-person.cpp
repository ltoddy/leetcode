class Solution
{
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int maxdis = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (i == 0) {
                int q = i;
                while (seats[q] != 1 && q < seats.size()) q++;
                maxdis = max(maxdis, abs(i - q));
            } else if (i == seats.size() - 1) {
                int p = i;
                while (seats[p] != 1 && p >= 0) p--;
                maxdis = max(maxdis, abs(i - p));
            } else {
                if (seats[i] == 0) {
                    int p = i, q = i;
                    while (seats[p] != 1 && p >= 0) p--;
                    while (seats[q] != 1 && q < seats.size()) q++;
                    maxdis = max(maxdis, min(abs(i - p), abs(i - q)));
                }
            }
        }
        return maxdis;
    }
};
