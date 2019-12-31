class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_max = 0, cur_end = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur_max = max(cur_max, i + nums[i]);
            if (i > cur_end) {
                return false;
            }
            if (i == cur_end) {
                cur_end = cur_max;
            }
        }
        return true;
    }
};
