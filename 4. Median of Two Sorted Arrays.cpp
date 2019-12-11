class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int index1 = 0, index2 = 0, left_index = 0, right_index = n, half_index = (n + m + 1) / 2;
        int max_left = 0, min_right = 0;
        while (left_index <= right_index) {
            index1 = (left_index + right_index) / 2;
            index2 = half_index - index1;
            if (index1 > 0 && index2 < m && nums1[index1 - 1] > nums2[index2]) {
                right_index = index1 - 1;
            } else if (index1 < n && index2 > 0 && nums1[index1] < nums2[index2 - 1]) {
                left_index = index1 + 1;    
            } else {
                if (index1 == 0) {
                    max_left = nums2[index2 - 1];
                } else if (index2 == 0) {
                    max_left = nums1[index1 - 1];
                } else {
                    max_left = max(nums1[index1 - 1], nums2[index2 - 1]);
                }
                break;
            }
        }
        if ((n + m) % 2 == 1) {
            return max_left;
        }
        if (index1 == n) {
            min_right = nums2[index2];
        } else if (index2 == m) {
            min_right = nums1[index1];
        } else {
            min_right = min(nums1[index1], nums2[index2]);
        }
        return (max_left + min_right) / 2.0;
    }
};
