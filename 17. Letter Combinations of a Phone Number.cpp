class Solution {
public:
    string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) {
            return ans;
        }
        string tmp;
        dfs(ans, tmp, digits, 0);
        return ans;
    }

private:
    void dfs(vector<string>& ans, string& tmp, string digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        string letter = letters[digits[idx] - '0'];
        for (int i = 0; i < letter.size(); ++i) {
            tmp.push_back(letter[i]);
            dfs(ans, tmp, digits, idx + 1);
            tmp.pop_back();
        }
    }
};




class Solution {
public:
    string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        deque<string> q;
        q.push_back("");
        for (char digit : digits) {
            for (int i = q.size() - 1; i >= 0; --i) {
                string cur = q.front();
                q.pop_front();
                for (char c : letters[digit - '0']) {
                    q.push_back(cur + c);
                }
            }
        }
        return vector<string>(q.begin(), q.end());
    }
};
