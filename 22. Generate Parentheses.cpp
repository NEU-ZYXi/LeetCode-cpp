class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        dfs(ans, tmp, n, 0, 0);
        return ans;
    }
    
private:
    void dfs(vector<string>& ans, string& tmp, int n, int l, int r) {
        if (l == n && r == n) {
            ans.push_back(tmp);
            return;
        }
        if (l < n) {
            tmp.push_back('(');
            dfs(ans, tmp, n, l + 1, r);
            tmp.pop_back();
        }
        if (r < l) {
            tmp.push_back(')');
            dfs(ans, tmp, n, l, r + 1);
            tmp.pop_back();
        }
    }
};
