class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            string next;
            int cnt = 1;
            for (int j = 1; j <= ans.size(); ++j) {
                if (j == ans.size() || ans[j] != ans[j - 1]) {
                    next += to_string(cnt);
                    next += ans[j - 1];
                    cnt = 1;
                } else {
                    cnt++;
                }
            }
            ans = next;
        }
        return ans;
    }
};
