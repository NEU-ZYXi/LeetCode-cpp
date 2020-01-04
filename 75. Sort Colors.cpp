class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx0 = 0, idx1 = 0, idx2 = nums.size() - 1;
        while (idx1 <= idx2) {
            if (nums[idx1] == 1) {
                idx1++;
            } else if (nums[idx1] == 0) {
                swap(nums[idx0], nums[idx1]);
                idx0++;
                idx1++;
            } else {
                swap(nums[idx1], nums[idx2]);
                idx2--;
            }
        }
    }
};
