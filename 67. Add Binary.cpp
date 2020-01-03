class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int n = a.size() - 1, m = b.size() - 1, sum = 0;
        while (n >= 0 || m >= 0) {
            sum /= 2;
            if (n >= 0) {
                sum += a[n] - '0';
                n--;
            }
            if (m >= 0) {
                sum += b[m] - '0';
                m--;
            }
            ans = to_string(sum % 2) + ans;
        }
        if (sum >= 2) {
            ans = "1" + ans;
        }
        return ans;
    }
};
