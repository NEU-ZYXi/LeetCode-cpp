class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i = 0;
        if (n == 0) {
            return 1;
        }
        while (i < n) {
            if (0 <= nums[i] && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }
        int ans = 1;
        while (ans < n && ans == nums[ans]) {
            ans++;
        }
        return nums[0] == ans ? ans + 1 : ans;
    }
};
