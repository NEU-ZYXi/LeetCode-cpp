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




class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, vector<string>> map;
        if (dict.find(endWord) == dict.end()) {
            return ans;
        }
        unordered_set<string> begin_set, end_set;
        begin_set.insert(beginWord);
        end_set.insert(endWord);
        bfs(map, dict, begin_set, end_set);
        vector<string> tmp;
        tmp.push_back(beginWord);
        dfs(ans, tmp, map, beginWord, endWord);
        return ans;
    }
    
private:
    void bfs(unordered_map<string, vector<string>>& map, unordered_set<string>& dict, unordered_set<string>& begin_set, unordered_set<string>& end_set) {
        bool stop_flag = false, reverse_flag = false;
        while (begin_set.size() && !stop_flag) {
            for (string s : begin_set) {
                dict.erase(s);
            }
            for (string s : end_set) {
                dict.erase(s);
            }
            if (begin_set.size() > end_set.size()) {
                swap(begin_set, end_set);
                reverse_flag = !reverse_flag;
            }
            unordered_set<string> next_set;
            for (string cur : begin_set) {
                for (int i = 0; i < cur.size(); ++i) {
                    string nxt = cur;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (nxt[i] != c) {
                            nxt[i] = c;
                            if (end_set.find(nxt) != end_set.end()) {
                                stop_flag = true;
                                if (reverse_flag) {
                                    map[nxt].push_back(cur);
                                } else {
                                    map[cur].push_back(nxt);
                                }
                            }
                            if (dict.find(nxt) != dict.end()) {
                                next_set.insert(nxt);
                                if (reverse_flag) {
                                    map[nxt].push_back(cur);
                                } else {
                                    map[cur].push_back(nxt);
                                }
                            }
                        }
                        nxt = cur;
                    }
                }
            }
            begin_set = next_set;
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
