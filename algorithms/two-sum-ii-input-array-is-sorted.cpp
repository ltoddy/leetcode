class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if (sum > target) right--;
            else if (sum < target) left++;
            else break;
        }

        return {left + 1, right + 1};
    }
};
