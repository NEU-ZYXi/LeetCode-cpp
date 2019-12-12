class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string ans = "";
        vector<string> rows(numRows, "");
        int cur_row = 0, step = 1;
        for (int i = 0; i < s.size(); ++i) {
            rows[cur_row] += s[i];
            if (cur_row == 0) {
                step = 1;
            } else if (cur_row == numRows - 1) {
                step = -1;
            }
            cur_row += step;
        }
        for (string row : rows) {
            ans += row;
        }
        return ans;
    }
};
