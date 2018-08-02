class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(1 + rowIndex);
        res[0] = 1;
        for (int i = 0; i < res.size(); i++) {
            for (int j = i; j > 0; j--)
                res[j] = res[j] + res[j - 1];
        }
        return res;
    }
};
