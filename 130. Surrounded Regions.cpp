class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) {
            return;
        }
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][m - 1] == 'O') {
                dfs(board, i, m - 1);
            }
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[n - 1][j] == 'O') {
                dfs(board, n - 1, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, int x, int y) {
        int n = board.size(), m = board[0].size();
        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int nx = dirs[i][0] + x, ny = dirs[i][1] + y;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && board[nx][ny] == 'O') {
                dfs(board, nx, ny);
            }
        }
    } 
};
