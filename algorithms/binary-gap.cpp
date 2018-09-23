class Solution
{
public:
    int binaryGap(int N)
    {
        int max = 0, pos = -1, curpos = 0;
        while (N > 0) {
            if (N % 2 == 1) {
                if (curpos - pos > max && pos != -1)
                    max = curpos - pos;
                pos = curpos;
            }
            N >>= 1;
            curpos++;
        }
        return max;
    }
};
