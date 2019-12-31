class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) {
            return ans;
        }
        int min_row = 0, max_row = matrix.size() - 1, min_col = 0, max_col = matrix[0].size() - 1;
        while (min_row <= max_row && min_col <= max_col) {
            for (int i = min_col; i <= max_col; ++i) {
                ans.push_back(matrix[min_row][i]);
            }
            min_row++;
            for (int i = min_row; i <= max_row; ++i) {
                ans.push_back(matrix[i][max_col]);
            }
            max_col--;
            if (min_row > max_row || min_col > max_col) {
                break;
            }
            for (int i = max_col; i >= min_col; --i) {
                ans.push_back(matrix[max_row][i]);
            }
            max_row--;
            for (int i = max_row; i >= min_row; --i) {
                ans.push_back(matrix[i][min_col]);
            }
            min_col++;
        }
        return ans;
    }
};
