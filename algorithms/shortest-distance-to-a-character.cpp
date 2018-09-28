class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> indexes, positions;
        for (int i = 0; i < S.length(); i++)
            if (S[i] == C) indexes.push_back(i);

        for (int i = 0; i < S.length(); i++) {
            int tmp = INT_MAX;
            for (int k = 0; k < indexes.size(); k++) tmp = min(tmp, abs(indexes[k] - i));
            positions.push_back(tmp);
        }
        return positions;
    }
};
