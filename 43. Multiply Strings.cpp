class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size(), m = num2.size();
        vector<int> tmp(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = prod + tmp[p2];
                tmp[p1] += sum / 10;
                tmp[p2] = sum % 10;
            }
        }
        string ans = "";
        for (int i = 0; i < n + m; ++i) {
            if (ans.size() != 0 || tmp[i] != 0) {
                ans += to_string(tmp[i]);
            }
        }
        return ans.size() == 0 ? "0" : ans;
    }
};
