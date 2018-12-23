class Solution
{
public:
    int reachNumber(int target)
    {
        if (target < 0) return reachNumber(-target);

        int i = 0;
        for (; i * (i + 1) < 2 * target; i++);

        if (i * (i + 1) / 2 == target) return i;
        else {
            if ((i * (i + 1) / 2 - target) % 2 == 0) return i;
            else {
                if (i % 2 == 0) return i + 1;
                else return i + 2;
            }
        }
    }
};
