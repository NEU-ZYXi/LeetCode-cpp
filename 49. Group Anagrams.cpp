class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        for (unordered_map<string, vector<string>>::iterator it = map.begin(); it != map.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
};
