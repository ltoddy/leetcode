class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;
        auto length = nums.size();

        while (index < length) {
            if (nums[index] == val) {
                length--;
                nums[index] = nums[length];
            } else {
                index++;
            }
        }

        return static_cast<int>(length);
    }
};
