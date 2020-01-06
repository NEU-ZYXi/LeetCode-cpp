class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(ans, tmp, nums, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums, int idx) {
        ans.push_back(tmp);
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            tmp.push_back(nums[i]);
            dfs(ans, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};
