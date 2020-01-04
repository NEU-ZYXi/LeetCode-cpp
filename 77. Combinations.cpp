class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, n, k, 1);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, int n, int k, int cur) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        for (int i = cur; i <= n; ++i) {
            tmp.push_back(i);
            dfs(ans, tmp, n, k, i + 1);
            tmp.pop_back();
        }
    }
};
