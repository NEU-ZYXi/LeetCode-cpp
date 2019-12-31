class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tmp;
        bool cols[n], diag1[2 * n - 1], diag2[2 * n - 1];
        fill_n(cols, n, false);
        fill_n(diag1, 2 * n - 1, false);
        fill_n(diag2, 2 * n - 1, false);
        dfs(ans, tmp, cols, diag1, diag2, n, 0);
        return ans;
    }
    
private:
    void dfs(vector<vector<string>>& ans, vector<string>& tmp, bool cols[], bool diag1[], bool diag2[], int n, int row) {
        if (row == n) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(string(n, '.'));
        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) {
                continue;
            }
            tmp.back()[col] = 'Q';
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n - 1] = true;
            dfs(ans, tmp, cols, diag1, diag2, n, row + 1);
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n - 1] = false;
            tmp.back()[col] = '.';
        }
        tmp.pop_back();
    }
};
