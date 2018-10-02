class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string result;
        int carry = 0;
        int length1 = num1.length(), length2 = num2.length();
        while (length1 > 0 || length2 > 0 || carry > 0) {
            int sum = carry;
            if (length1 > 0) {
                length1--;
                sum = sum + num1[length1] - '0';
            }
            if (length2 > 0) {
                length2--;
                sum = sum + num2[length2] - '0';
            }
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
