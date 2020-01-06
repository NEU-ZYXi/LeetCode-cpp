class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string tmp;
        dfs(ans, tmp, s, 0, 0);
        return ans;
    }
    
private:
    void dfs(vector<string>& ans, string& tmp, string& s, int idx, int cnt) {
        if (cnt == 4) {
            if (idx == s.size()) {
                ans.push_back(tmp);
            }
            return;
        }
        for (int len = 1; len < 4; ++len) {
            if (idx + len > s.size()) {
                break;
            }
            string ip = s.substr(idx, len);
            if ((ip.size() > 1 && ip[0] == '0') || stoi(ip) > 255) {
                continue;
            }
            string nxt = tmp + ip + (cnt == 3 ? "" : ".");
            dfs(ans, nxt, s, idx + len, cnt + 1);
        }
    }
};
