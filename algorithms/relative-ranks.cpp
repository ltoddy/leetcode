class Solution
{
public:
    vector<string> findRelativeRanks(vector<int>& nums)
    {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end(), [](int a, int b) -> bool { return a > b; });
        vector<string> res = vector<string>(nums.size());

        for (int j = 0; j < arr.size(); j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == arr[j]) {
                    switch(j) {
                        case 0:
                            res[i] = "Gold Medal";
                            break;
                        case 1:
                            res[i] = "Silver Medal";
                            break;
                        case 2:
                            res[i] = "Bronze Medal";
                            break;
                        default:
                            res[i] = to_string(j + 1);
                            break;
                    }
                    break;
                }
            }
        }
        return res;
    }
};
