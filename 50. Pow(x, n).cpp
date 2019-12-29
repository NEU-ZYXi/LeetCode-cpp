class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) {
            return 1;
        }
        if (x == -1) {
            return n & 1 == 1 ? -1 : 1;
        }
        if (n == INT_MIN) {
            return 0;
        }
        if (n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        double ans = 1;
        while (n > 0) {
            if (n & 1 == 1) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
