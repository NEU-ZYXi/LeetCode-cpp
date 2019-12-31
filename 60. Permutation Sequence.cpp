class Solution {
public:
    string getPermutation(int n, int k) {
        int total = 1;
        vector<int> digits;
        for (int i = 1; i <= n; ++i) {
            total *= i;
            digits.push_back(i);
        }
        string ans;
        for (int i = n; i > 0; --i) {
            total /= i;
            int idx = (k - 1) / total;
            ans += to_string(digits[idx]);
            digits.erase(digits.begin() + idx);
            k -= total * idx;
        }
        return ans;
    }
};
