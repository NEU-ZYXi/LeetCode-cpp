class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i > 1 ? dp[i - 2] : 0) + 2;
                } else if (i > dp[i - 1] && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = (i > dp[i - 1] + 1 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};




class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    st.push(i);
                } else {
                    if (s[st.top()] == '(') {
                        st.pop();
                    } else {
                        st.push(i);
                    }
                }
            }
        }
        if (st.empty()) {
            return n;
        } else {
            int start = 0, end = n;
            while (!st.empty()) {
                start = st.top();
                st.pop();
                ans = max(ans, end - start - 1);
                end = start;
            }
            ans = max(ans, end);
        }
        return ans;
    }
};
