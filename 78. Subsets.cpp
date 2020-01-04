class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, nums, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums, int idx) {
        ans.push_back(tmp);
        for (int i = idx; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            dfs(ans, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};




class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), total = 1 << n;
        vector<vector<int>> ans(total, vector<int>());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < total; ++j) {
                if ((j >> i) & 1 == 1) {
                    ans[j].push_back(nums[i]);
                }
            }
        }
        return ans;
    }
};
