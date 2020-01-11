class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return ans;
        }
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                string cur = q.front();
                q.pop();
                if (cur == endWord) {
                    return ans + 1;
                }
                for (int j = 0; j < cur.size(); ++j) {
                    string nxt = cur;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (nxt[j] != c) {
                            nxt[j] = c;
                            if (dict.find(nxt) != dict.end()) {
                                dict.erase(nxt);
                                q.push(nxt);
                            }
                        }
                        nxt = cur;
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
