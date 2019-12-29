class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        unordered_set<int> visited;
        dfs(ans, tmp, visited, nums);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, unordered_set<int>& visited, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (visited.count(nums[i]) == 0) {
                tmp.push_back(nums[i]);
                visited.insert(nums[i]);
                dfs(ans, tmp, visited, nums);
                visited.erase(nums[i]);
                tmp.pop_back();
            }
        }
    }
};
