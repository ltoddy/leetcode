class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        vector<int> position;
        for (int i = 0; i < S.length(); i++) {
            if (isalpha(S[i])) position.push_back(i);
        }

        for (int i = 0; i < position.size() / 2; i++) {
            char t = S[position[i]];
            S[position[i]] = S[position[position.size() - i - 1]];
            S[position[position.size() - i - 1]] = t;
        }
        return S;
    }
};
