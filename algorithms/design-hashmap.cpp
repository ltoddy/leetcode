class MyHashMap
{
private:
    vector<int> data = vector<int>(1000010, -1);

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
    }

    /** value will always be positive. */
    void put(int key, int value)
    {
        this->data[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        return this->data[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        this->data[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
