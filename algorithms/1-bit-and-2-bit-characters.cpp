class Solution
{
public:
    bool isOneBitCharacter(vector<int>& bits)
    {
        int index;
        for (index = 0; index < bits.size() - 1; index++) {
            if (bits[index] == 1) index += 1;
        }
        return index == bits.size() - 1;
    }
};
