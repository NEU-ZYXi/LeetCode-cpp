class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        vector<int> ans(n, 0);
        for (int j = 0; j < n; ++j) {
            int min_cut = INT_MAX;
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    min_cut = i == 0 ? 0 : min(min_cut, ans[i - 1] + 1);
                }
            }
            ans[j] = min_cut;
        }
        return ans[n - 1];
    }
};
