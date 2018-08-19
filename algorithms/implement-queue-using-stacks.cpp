class MyQueue
{
private:
    vector<int> data;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        this->data.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int res = this->data.front();
        this->data.erase(this->data.begin(), this->data.begin() + 1);
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        return this->data.front();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return this->data.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
 