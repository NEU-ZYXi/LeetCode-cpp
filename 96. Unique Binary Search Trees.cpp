class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= len; ++i) {
                dp[len] += dp[i - 1] * dp[len - i];
            }
        }
        return dp[n];
    }
};
