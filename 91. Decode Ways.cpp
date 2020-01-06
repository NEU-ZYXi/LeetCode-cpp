class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), cur = 0, prev = 0;
        if (n == 0) {
            return 0;
        }
        cur = s[0] == '0' ? 0 : 1;
        if (n == 1) {
            return cur;
        }
        for (int i = 1; i < n; ++i) {
            int tmp = 0;
            if (s[i] != '0') {
                tmp = cur;
            }
            if (s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) {
                tmp += i > 1 ? prev : 1;
            }
            prev = cur;
            cur = tmp;
        }
        return cur;
    }
};
