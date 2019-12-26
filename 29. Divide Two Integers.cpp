class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && (divisor == -1 || divisor == 1)) {
            return divisor == -1 ? INT_MAX : INT_MIN;
        }
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long dvd = abs((long)dividend);
        long dvs = abs((long)divisor);
        int ans = 0;
        while (dvd >= dvs) {
            long tmp = dvs, cnt = 1;
            while (dvd >= (tmp << 1)) {
                tmp <<= 1;
                cnt <<= 1;
            }
            dvd -= tmp;
            ans += cnt;
        }
        return sign * ans;
    }
};
