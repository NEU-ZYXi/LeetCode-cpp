class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(ans, tmp, candidates, target, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& candidates, int target, int idx) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            dfs(ans, tmp, candidates, target - candidates[i], i + 1);
            tmp.pop_back();
        }
    }
};
