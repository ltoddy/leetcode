class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = string("");

        int inc = 0;
        auto i = static_cast<int>(a.size() - 1), j = static_cast<int>(b.size() - 1);
        while (i >= 0 || j >= 0 || inc == 1) {
            inc += i >= 0 ? a[i--] - '0' : 0;
            inc += j >= 0 ? b[j--] - '0' : 0;
            s = static_cast<char>(inc % 2 + '0') + s;
            inc /= 2;
        }
        return s;
    }
};
