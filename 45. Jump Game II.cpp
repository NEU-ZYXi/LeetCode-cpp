class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, cur_max = 0, cur_end = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            cur_max = max(cur_max, i + nums[i]);
            if (i == cur_end) {
                cur_end = cur_max;
                ans++;
            }
        }
        return ans;
    }
};
