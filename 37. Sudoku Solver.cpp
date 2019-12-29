class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; ++k) {
                        if (is_valid(board, i, j, k)) {
                            board[i][j] = k;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool is_valid(vector<vector<char>>& board, int i, int j, char c) {
        for (int k = 0; k < board.size(); ++k) {
            if (board[i][k] == c) {
                return false;
            }
            if (board[k][j] == c) {
                return false;
            }
            if (board[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3] == c) {
                return false;
            }
        }
        return true;
    }
};
