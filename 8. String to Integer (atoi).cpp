class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) {
            return 0;
        }
        int i = 0, sign = 1, ans = 0;
        while (str[i] == ' ') {
            i++;
        }
        if (i == str.size()) {
            return 0;
        }
        if (str[i] == '+' || str[i] == '-') {
            sign = str[i] == '+' ? 1 : -1;
            i++;
        }
        while (i < str.size()) {
            int digit = str[i] - '0';
            if (digit < 0 || digit > 9) {
                break;
            }
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + digit;
            i++;
        }
        return sign * ans;
    }
};
