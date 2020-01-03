class Solution {
public:
    int climbStairs(int n) {
        int first = 0, second = 1, ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = first + second;
            first = second;
            second = ans;
        }
        return ans;
    }
};
