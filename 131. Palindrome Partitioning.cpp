class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> tmp;
        dfs(ans, tmp, s, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<string>>& ans, vector<string>& tmp, string& s, int idx) {
        if (idx == s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            string cur = s.substr(idx, i - idx + 1);
            if (is_palindrome(cur)) {
                tmp.push_back(cur);
                dfs(ans, tmp, s, i + 1);
                tmp.pop_back();
            }
        }
    }
    
    bool is_palindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};




class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
            }
        }
        vector<string> tmp;
        dfs(ans, tmp, dp, s, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<string>>& ans, vector<string>& tmp, vector<vector<bool>>& dp, string s, int idx) {
        if (idx == s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < s.size(); ++i) {
            if (dp[idx][i]) {
                tmp.push_back(s.substr(idx, i - idx + 1));
                dfs(ans, tmp, dp, s, i + 1);
                tmp.pop_back();
            }
        }
    }
};
