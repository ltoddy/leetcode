class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        return static_cast<double>(nums1[ceil(static_cast<double>(nums1.size() - 1) / 2)] +
                                   nums1[floor(static_cast<double>(nums1.size() - 1) / 2)]) / 2;
    }
};
