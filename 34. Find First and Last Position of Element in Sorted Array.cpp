class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        if (nums.empty()) {
            return ans;
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l ) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (nums[l] == target) {
            ans[0] = l;
        } else {
            return ans;
        }
        r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[r] == target) {
            ans[1] = r;
        } else {
            return vector<int>{-1, -1};
        }
        return ans;
    }
};
