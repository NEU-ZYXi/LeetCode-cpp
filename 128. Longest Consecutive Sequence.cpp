class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int ans = 0, cnt = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] == nums[i - 1] + 1) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};




class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i], cnt = 1;
            while (set.find(cur - 1) != set.end()) {
                set.erase(cur - 1);
                cnt++;
                cur--;
            }
            cur = nums[i];
            while (set.find(cur + 1) != set.end()) {
                set.erase(cur + 1);
                cnt++;
                cur++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
