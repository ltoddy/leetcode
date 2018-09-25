class MyCircularQueue {
private:
    vector<int> data;
    int front = 0, rear = 0;
    bool full = false;

    int size()
    {
        if (this->full) return this->data.size();

        if (this->front <= this->rear) {
            return this->rear - this->front;
        } else {
            return this->rear + this->data.size() - this->front;
        }
    }

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        this->data = vector<int>(k, -1);
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (this->isFull()) return false;

        this->rear = (this->rear + 1) % this->data.size();
        this->data[this->rear % this->data.size()] = value;

        if (this->rear == this->front) {
            this->full = true;
        }

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (this->isEmpty()) return false;

        this->front = (this->front + 1) % this->data.size();
        this->full = false;
        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (this->isEmpty()) return -1;
        return this->data[(this->front + 1) % this->data.size()];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (this->isEmpty()) return -1;
        return this->data[this->rear];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return this->size() == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return this->full;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */
