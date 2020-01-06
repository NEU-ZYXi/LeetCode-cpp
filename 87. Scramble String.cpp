class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int n = s1.size();
        vector<int> buckets(128, 0);
        for (int i = 0; i < n; ++i) {
            buckets[s1[i]]++;
            buckets[s2[i]]--;
        }
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i] != 0) {
                return false;
            }
        }
        for (int len = 1; len < n; ++len) {
            if (isScramble(s1.substr(0, len), s2.substr(0, len)) && isScramble(s1.substr(len), s2.substr(len))) {
                return true;
            }
            if (isScramble(s1.substr(0, len), s2.substr(n - len)) && isScramble(s1.substr(len), s2.substr(0, n - len))) {
                return true;
            }
        }
        return false;
    }
};
