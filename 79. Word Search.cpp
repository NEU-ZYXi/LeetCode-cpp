class Solution {
public:
    int dirs[4][2] {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int idx) {
        int n = board.size(), m = board[0].size();
        if (idx == word.size() - 1) {
            return true;
        }
        char tmp = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && word[idx + 1] == board[nx][ny]) {
                if (dfs(board, word, nx, ny, idx + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = tmp;
        return false;
    }
};
