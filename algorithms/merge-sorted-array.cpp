class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int end = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] != 0) {
                end++;
            } else {
                break;
            }
        }
        nums1.insert(nums1.begin() + end, nums2.begin(), nums2.end());
        nums1.resize(m + n);
        sort(nums1.begin(), nums1.end());
    }
};
