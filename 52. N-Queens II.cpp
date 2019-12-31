class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        bool cols[n], diag1[2 * n - 1], diag2[2 * n - 1];
        fill_n(cols, n, false);
        fill_n(diag1, 2 * n - 1, false);
        fill_n(diag2, 2 * n - 1, false);
        dfs(cols, diag1, diag2, n, 0, ans);
        return ans;
    }
    
private:
    void dfs(bool cols[], bool diag1[], bool diag2[], int n, int row, int& ans) {
        if (row == n) {
            ans++;
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue;
            }
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;
            dfs(cols, diag1, diag2, n, row + 1, ans);
            diag2[row - col + n - 1] = false;
            diag1[row + col] = false;
            cols[col] = false;
        }
    }
};
