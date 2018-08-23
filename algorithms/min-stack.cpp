class MinStack
{
private:
    vector<int> data;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        this->data.push_back(x);
    }

    void pop()
    {
        this->data.pop_back();
    }

    int top()
    {
        return this->data[this->data.size() - 1];
    }

    int getMin()
    {
        int min = INT_MAX;
        for (int i = 0; i < this->data.size(); i++) {
            if (this->data[i] < min) {
                min = this->data[i];
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
