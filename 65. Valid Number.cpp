class Solution {
public:
    bool isNumber(string s) {
        if (s.size() == 0) {
            return false;
        }
        bool has_num = false, has_e = false, has_point = false;
        int sign_cnt = 0;
        s.erase(s.find_last_not_of(' ') + 1);
        s.erase(0, s.find_first_not_of(' '));
        if (s.size() == 0) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (('0' > s[i] || s[i] > '9') && s[i] != 'e' && s[i] != 'E' && s[i] != '.' && s[i] != '+' && s[i] != '-') {
                return false;
            } else if ('0' <= s[i] && s[i] <= '9') {
                has_num = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (has_e || !has_num || i == s.size() - 1) {
                    return false;
                }
                has_e = true;
            } else if (s[i] == '.') {
                if (has_point || has_e) {
                    return false;
                }
                if (i == s.size() - 1 && !has_num) {
                    return false;
                }
                has_point = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (sign_cnt == 2 || i == s.size() - 1) {
                    return false;
                }
                if (i > 0 && !has_e) {
                    return false;
                }
                sign_cnt++;
            }
        }
        return true;
    }
};
