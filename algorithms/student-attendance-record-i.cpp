class Solution
{
public:
    bool checkRecord(string s)
    {
        int A_count = 0;
        bool L_double = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') A_count++;

            if (s[i] == 'L') {
                if (s[i + 1] == 'L' && s[i - 1] == 'L')
                    L_double = true;
            }
        }
        return A_count <= 1 && !L_double;
    }
};
