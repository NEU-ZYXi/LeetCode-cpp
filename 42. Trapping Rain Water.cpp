class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0, max_left = 0, max_right = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] < max_left) {
                    ans += max_left - height[l];
                } else {
                    max_left = height[l];
                }
                l++;
            } else {
                if (height[r] < max_right) {
                    ans += max_right - height[r];
                } else {
                    max_right = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};
