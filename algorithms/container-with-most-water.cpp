class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = INT_MIN;

        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int tmp = (j - i) * min(height[i], height[j]);
                area = tmp > area ? tmp : area;
            }
        }
        return area;
    }
};
