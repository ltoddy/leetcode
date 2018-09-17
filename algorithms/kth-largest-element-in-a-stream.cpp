class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> pque;
    int k;

public:
    KthLargest(int k, vector<int> nums)
    {
        this->k = k;
        for (auto num : nums) {
            pque.push(num);
            if (pque.size() > k)
                pque.pop();
        }
    }

    int add(int val)
    {
        pque.push(val);
        if (pque.size() > this->k) pque.pop();
        return pque.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
