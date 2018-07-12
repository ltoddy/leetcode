class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A == B) return true;
        const auto len = A.length();
        for (auto i = 0; i < len; i++) {
            A.append(&A.front(), 1);
            A.erase(A.begin(), A.begin() + 1);
            if (A == B) return true;
        }

        return false;
    }
};
