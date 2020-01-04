class Solution {
public:
    string simplifyPath(string path) {
        string ans, cur;
        vector<string> stk;
        stringstream s(path);
        while (getline(s, cur, '/')) {
            if (cur == "." || cur == "") {
                continue;
            } else if (cur == ".." && !stk.empty()) {
                stk.pop_back();
            } else if (cur != "..") {
                stk.push_back(cur);
            }
        }
        for (string str : stk) {
            ans += "/" + str;
        }
        return ans.empty() ? "/" : ans;
    }
};
