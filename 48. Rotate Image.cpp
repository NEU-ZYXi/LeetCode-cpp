class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = matrix.size() - 1;
        while (i < j) {
            swap(matrix[i], matrix[j]);
            i++;
            j--;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[0].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
