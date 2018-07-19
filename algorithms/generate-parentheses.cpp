class Solution
{
public:
    void generateParenthesis(vector<string>& res, string s, int restl, int restr)
//    restl 与 restr 代表左括号和右括号的剩余数量
    {
        if (restl == 0 && restr == 0) res.push_back(s);

        if (restl > 0) generateParenthesis(res, s + "(", restl - 1, restr); // 先亚入左括号
        if (restr > 0 && restl < restr) generateParenthesis(res, s + ")", restl, restr - 1); // 剩余右括号比左括号多的时候才压入
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        generateParenthesis(res, "", n, n);
        return res;
    }
};
