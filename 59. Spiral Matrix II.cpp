class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int min_row = 0, max_row = n - 1, min_col = 0, max_col = n - 1, cur = 1;
        while (cur <= n * n) {
            for (int i = min_col; i <= max_col; ++i) {
                ans[min_row][i] = cur++;
            }
            min_row++;
            for (int i = min_row; i <= max_row; ++i) {
                ans[i][max_col] = cur++;
            }
            max_col--;
            for (int i = max_col; i >= min_col; --i) {
                ans[max_row][i] = cur++;
            }
            max_row--;
            for (int i = max_row; i >= min_row; --i) {
                ans[i][min_col] = cur++;
            }
            min_col++;
        }
        return ans;
    }
};
