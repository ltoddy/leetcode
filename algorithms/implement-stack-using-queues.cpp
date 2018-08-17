class MyStack
{
private:
    int head = 0;
    vector<int> data;
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        this->data.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int res = this->data[this->data.size() - 1];
        this->data.pop_back();
        return res;
    }

    /** Get the top element. */
    int top()
    {
        return this->data[this->data.size() - 1];
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return this->data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
 