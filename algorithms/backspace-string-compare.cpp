class Solution {
private:
    void intsertToStack(stack<char>& st, string S)
    {
        for (auto s : S) {
            if (s == '#') {
                if (!st.empty()) {
                    st.pop();
                }
                continue;
            }
            st.push(s);
        }
    }

public:
    bool backspaceCompare(string S, string T)
    {
        stack<char> ss, ts;

        this->intsertToStack(ss, S);
        this->intsertToStack(ts, T);

        return ss == ts;
    }
};
