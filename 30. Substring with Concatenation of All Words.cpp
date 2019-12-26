class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) {
            return ans;
        }
        unordered_map<string, int> map;
        unordered_map<string, int> cur_map;
        for (string word : words) {
            map[word]++;
        }
        int n = words.size(), s_len = s.size(), w_len = words[0].size();
        for (int i = 0; i < w_len; ++i) {
            int start = i, end = i, cnt = 0;
            while (end <= s_len - w_len) {
                string cur_str = s.substr(end, w_len);
                if (map.count(cur_str) == 0) {
                    cnt = 0;
                    start = end + w_len;
                    cur_map.clear();
                } else {
                    cur_map[cur_str]++;
                    cnt++;
                    while (cur_map[cur_str] > map[cur_str]) {
                        string left_str = s.substr(start, w_len);
                        cur_map[left_str]--;
                        cnt--;
                        start += w_len;
                    }
                    if (cnt == n) {
                        ans.push_back(start);
                    }
                }
                end += w_len;
            }
            cur_map.clear();
        }
        return ans;
    }
};
