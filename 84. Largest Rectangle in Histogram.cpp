class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        if (n == 0) {
            return ans;
        }
        vector<int> left(n, 0), right(n, 0);
        left[0] = -1;
        right[n - 1] = n;
        for (int i = 1; i < n; ++i) {
            int j = i - 1;
            while (j > -1 && heights[j] >= heights[i]) {
                j = left[j];
            }
            left[i] = j;
        }
        for (int i = n - 2; i >= 0; --i) {
            int j = i + 1;
            while (j < n && heights[j] >= heights[i]) {
                j = right[j];
            }
            right[i] = j;
        }
        for (int i = 0; i < n; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
