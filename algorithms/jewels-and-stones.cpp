class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        map<char, bool> kinds;
        for (char jewle : J) kinds[jewle] = true;
        int res = 0;
        for (char stone : S)
            if (kinds[stone]) res++;
        return res;
    }
};
