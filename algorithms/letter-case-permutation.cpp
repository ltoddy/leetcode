class Solution
{
private:
    void backtracke(vector<string>& res, string S, int index)
    {
        if (index > S.length()) {
            res.push_back(S);
            return;
        }

        if (S[index] >= 'a' && S[index] <= 'z') {
            S[index] -= 32;
            backtracke(res, S, index + 1);
            S[index] += 32;
        }
        if (S[index] >= 'A' && S[index] <= 'Z') {
            S[index] += 32;
            backtracke(res, S, index + 1);
            S[index] -= 32;
        }
        backtracke(res, S, index + 1);
    }

public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        this->backtracke(res, S, 0);
        return res;
    }
};
