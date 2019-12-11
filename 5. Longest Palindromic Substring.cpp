class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
                if (dp[i][j] && ans.size() < j - i + 1) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        int i = 0, start = 0, max_len = 1;
        while (i < n && n - i > max_len / 2) {
            int left = i, right = i;
            while (right < n - 1 && s[right] == s[right + 1]) {
                right++;
            }
            i = right + 1;
            while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                left--;
                right++;
            }
            if (max_len < right - left + 1) {
                start = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(start, max_len);
    }
};
