class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        digits[digits.size() - 1] += 1;
        for (auto i = digits.size() - 1; i > 0; i--) {
            int inc = 0;
            if (digits[i] >= 10) {
                inc = digits[i] / 10;
                digits[i] = digits[i] % 10;
                digits[i - 1] = digits[i - 1] + inc;
            }
        }
        if (digits[0] >= 10) {
            int div = digits[0] / 10;
            int mod = digits[0] % 10;
            digits[0] = mod;
            digits.insert(digits.begin(), div);
        }
        return digits;
    }
};
