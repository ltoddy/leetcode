class Solution
{
public:
    string toLowerCase(string str)
    {
        int diff = 'A' - 'a';

        string res;

        for (char c: str) {
            if (isupper(c))
                c = static_cast<char>(c - diff);
            res.push_back(c);
        }

        return res;
    }
};
