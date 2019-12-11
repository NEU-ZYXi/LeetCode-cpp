class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.count(nums[i]) > 0) {
                ans.push_back(map[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            map[target - nums[i]] = i;
        }
        return vector<int> {0, 0};
    }
};
