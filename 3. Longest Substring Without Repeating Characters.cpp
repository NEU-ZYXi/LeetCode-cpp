class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> map;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (map.count(s[j]) > 0) {
                i = max(i, map[s[j]] + 1);
            }
            map[s[j]] = j;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};
