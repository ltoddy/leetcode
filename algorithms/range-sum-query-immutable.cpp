class NumArray
{
private:
    vector<int> nums;
    vector<int> store;

public:
    NumArray(vector<int> nums)
    {
        this->nums = nums;
        this->store = vector<int>(nums.size(), 0);

        if (nums.size() > 0) {
            store[0] = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                store[i] = store[i - 1] + nums[i];
            }
        }
    }

    int sumRange(int i, int j)
    {
        return store[j] - store[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
