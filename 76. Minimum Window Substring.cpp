class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map;
        for (char c : t) {
            map[c]++;
        }
        string ans = "";
        int cnt = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (map.find(s[j]) != map.end()) {
                map[s[j]]--;
                if (map[s[j]] >= 0) {
                    cnt++;
                }
            }
            while (cnt == t.size()) {
                if (ans == "" || ans.size() > j - i + 1) {
                    ans = s.substr(i, j - i + 1);
                }
                if (map.find(s[i]) != map.end()) {
                    map[s[i]]++;
                    if (map[s[i]] > 0) {
                        cnt--;
                    }
                }
                i++;
            }
        }
        return ans;
    }
};
