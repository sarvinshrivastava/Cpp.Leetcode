class Solution {
public:
    bool flag = false;
    vector<int> move = {0, 1, 0, -1, 0};

    void reccurse(vector<vector<char>>& board, vector<vector<bool>>& hasVisited,
                  string& word, int idx, int x, int y, int& m, int& n) {
        if (idx == word.size()) {
            flag = true;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + move[i];
            int ny = y + move[i + 1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                if (board[nx][ny] == word[idx] && hasVisited[nx][ny] != true) {
                    hasVisited[nx][ny] = true;
                    reccurse(board, hasVisited, word, idx + 1, nx, ny, m, n);
                    hasVisited[nx][ny] = false;
                }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> hasVisited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (word[0] == board[i][j]) {
                    hasVisited[i][j] = true;
                    reccurse(board, hasVisited, word, 1, i, j, m, n);
                    hasVisited[i][j] = false;

                    if (flag == true)
                        return true;
                }

        return false;
    }
};
