class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};




class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, asterisk_i = 0, asterisk_j = -1;
        while (i < s.size()) {
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                asterisk_i = i;
                asterisk_j = j;
                j++;
            } else if (asterisk_j != -1) {
                i = ++asterisk_i;
                j = asterisk_j + 1;
            } else {
                return false;
            }
        }
        while (j < p.size() && p[j] == '*') {
            j++;
        }
        return j == p.size();
    }
};
