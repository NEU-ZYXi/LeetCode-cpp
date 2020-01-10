class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> map;
        if (dict.find(endWord) == dict.end()) {
            return ans;
        }
        bfs(map, dict, beginWord, endWord);
        vector<string> tmp;
        tmp.push_back(beginWord);
        dfs(ans, tmp, map, beginWord, endWord);
        return ans;
    }
    
private:
    void bfs(unordered_map<string, vector<string>>& map, unordered_set<string>& dict, string begin_word, string end_word) {
        queue<string> q;
        q.push(begin_word);
        unordered_set<string> visited;
        unordered_set<string> to_visit;
        to_visit.insert(begin_word);
        while (!q.empty()) {
            visited.insert(to_visit.begin(), to_visit.end());
            to_visit.clear();
            for (int i = q.size() - 1; i >= 0; --i) {
                string cur = q.front();
                q.pop();
                for (int j = 0; j < cur.size(); ++j) {
                    string nxt = cur;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (nxt[j] != c) {
                            nxt[j] = c;
                            if (dict.find(nxt) != dict.end() && visited.find(nxt) == visited.end()) {
                                map[cur].push_back(nxt);
                                if (to_visit.find(nxt) == to_visit.end()) {
                                    to_visit.insert(nxt);
                                    q.push(nxt);
                                }
                            }
                        }
                        nxt = cur;
                    }
                }
            }
        }
    }
    
    void dfs(vector<vector<string>>& ans, vector<string>& tmp, unordered_map<string, vector<string>>& map, string begin_word, string end_word) {
        if (begin_word == end_word) {
            ans.push_back(tmp);
            return;
        }
        for (string nxt : map[begin_word]) {
            tmp.push_back(nxt);
            dfs(ans, tmp, map, nxt, end_word);
            tmp.pop_back();
        }
    }
};
