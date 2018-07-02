class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty()) {
            return true;
        }

        stack<char> res;

        for (char c : s) {
            if (res.empty()) {
                res.push(c);
            } else if ((res.top() == '(' && c == ')') ||
                       (res.top() == '[' && c == ']') ||
                       (res.top() == '{' && c == '}')) {
                res.pop();
            } else {
                res.push(c);
            }
        }

        return res.empty();
    }
};
