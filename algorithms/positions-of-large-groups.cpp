class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> positions;
        int begin = 0, end = 0;
        for (; end < S.length(); end++) {
            if (S[begin] != S[end]) {
                if ((end - begin) >= 3)
                    positions.push_back({begin, end - 1});
                begin = end;
            }
        }
        if (end - begin >= 3) positions.push_back({begin, end - 1});
        return positions;
    }
};
