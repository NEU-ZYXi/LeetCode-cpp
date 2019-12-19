class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        string ans = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            int idx = 1;
            while (idx < strs.size()) {
                if (strs[idx][i] != strs[0][i]) {
                    return ans;
                }
                idx++;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
