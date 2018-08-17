class Solution
{
private:
    string getNext(const string& s)
    {
        stringstream ss;
        for (auto i = s.begin(); i != s.end();) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }
        return ss.str();
    }

public:
    string countAndSay(int n)
    {
        if (n == 1) return "1";

        string res("1");
        while (--n) {
            res = this->getNext(res);
        }
        return res;
    }
};
