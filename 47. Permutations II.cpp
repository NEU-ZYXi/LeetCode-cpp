class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        unordered_set<int> visited;
        sort(nums.begin(), nums.end());
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
            if (visited.count(i) > 0) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && visited.count(i - 1) == 0) {
                continue;
            }
            tmp.push_back(nums[i]);
            visited.insert(i);
            dfs(ans, tmp, visited, nums);
            visited.erase(i);
            tmp.pop_back();
        }
    }
};
