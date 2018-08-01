class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0) return "0";

        string res;
        char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        int cnt = 0;
        while (num != 0 && cnt < 32) {
            res.push_back(hex[num & 0xf]);
            num >>= 4;
            cnt += 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
