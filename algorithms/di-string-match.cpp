class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        int left = 0, right = S.length();
        vector<int> result;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'I') {
                result.push_back(left);
                left++;
            } else if (S[i] == 'D') {
                result.push_back(right);
                right--;
            }
        }
        result.push_back(right);
        return result;
    }
};
