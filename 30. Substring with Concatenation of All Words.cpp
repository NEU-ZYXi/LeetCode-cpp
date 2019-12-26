class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.size() == 0) {
            return ans;
        }
        unordered_map<string, int> map;
        for (string word : words) {
            map[word]++;
        }
        unordered_map<string, int> cur_map;
        int n = words.size(), s_len = s.size(), w_len = words[0].size();
        for (int i = 0; i < w_len; ++i) {
            int l = i, r = i, cnt = 0;
            while (r <= s_len - w_len) {
                string tmp = s.substr(r, w_len);
                if (map.count(tmp) == 0) {
                    cur_map.clear();
                    cnt = 0;
                    l = r + w_len;
                } else {
                    cur_map[tmp]++;
                    cnt++;
                    while (cur_map[tmp] > map[tmp]) {
                        string left_substr = s.substr(l, w_len);
                        cur_map[left_substr]--;
                        cnt--;
                        l += w_len;
                    }
                    if (cnt == n) {
                        ans.push_back(l);
                    }
                }
                r += w_len;
            }
            cur_map.clear();
        }
        return ans;
    }
};
