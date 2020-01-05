class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int ans = 0, n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            ans = max(ans, largest_rectangle_area(heights));
        }
        return ans;
    }
    
private:
    int largest_rectangle_area(vector<int>& heights) {
        int ans = 0, n = heights.size(), i = 0;
        vector<int> stk;
        while (i <= n) {
            int height = i == n ? 0 : heights[i];
            if (stk.empty() || height >= heights[stk.back()]) {
                stk.push_back(i);
                i++;
            } else {
                int j = stk.back();
                stk.pop_back();
                int len = stk.empty() ? i : i - stk.back() - 1;
                ans = max(ans, heights[j] * len);
            }
        }
        return ans;
    }
};
