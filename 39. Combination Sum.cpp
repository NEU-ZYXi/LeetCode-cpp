class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
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
            tmp.push_back(candidates[i]);
            dfs(ans, tmp, candidates, target - candidates[i], i);
            tmp.pop_back();
        }
    }
};
