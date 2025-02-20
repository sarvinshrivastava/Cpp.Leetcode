class Solution {
public:
    int moves[5] = {0, 1, 0, -1, 0};

    void DFS(vector<vector<char>>& board, int& m, int& n, int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + moves[i], ny = y + moves[i + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                board[nx][ny] = 'Y';
                DFS(board, m, n, nx, ny);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        // Column calls
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = 'Y';
                DFS(board, m, n, i, 0);
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = 'Y';
                DFS(board, m, n, i, n - 1);
            }
        }

        // Row calls
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O') {
                board[0][i] = 'Y';
                DFS(board, m, n, 0, i);
            }

            if (board[m - 1][i] == 'O') {
                board[m - 1][i] = 'Y';
                DFS(board, m, n, m - 1, i);
            }
        }

        // Undo
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
    }
};
