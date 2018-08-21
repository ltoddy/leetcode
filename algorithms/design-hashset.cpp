class MyHashSet
{
private:
    vector<bool> data;
public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        this->data = vector<bool>(1000010, false);
    }

    void add(int key)
    {
        this->data[key] = true;
    }

    void remove(int key)
    {
        this->data[key] = false;
    }

    /** Returns true if this set did not already contain the specified element */
    bool contains(int key)
    {
        return this->data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
