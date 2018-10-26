class Solution {
public:
    int repeatedStringMatch(string A, string B)
    {
        string tmp = A;
        for (int i = 1; i <= B.length() / A.size() + 2; i++) {
            if (tmp.find(B) != string::npos)
                return i;
            tmp += A;
        }
        return -1;
    }
};
