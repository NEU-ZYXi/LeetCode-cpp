class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, j = nums.size() - 1;
        while (i > 0) {
            if (nums[i] > nums[i - 1]) {
                break;
            }
            i--;
        }
        if (i != 0) {
            while (j > 0) {
                if (nums[j] > nums[i - 1]) {
                    break;
                }
                j--;
            }
            swap(nums[i - 1], nums[j]);
        }
        reverse(nums.begin() + i, nums.begin() + nums.size());
    }
};
