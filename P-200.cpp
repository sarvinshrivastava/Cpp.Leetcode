class Solution {
public:
    int move[5] = {0, 1, 0, -1, 0};

    void DFS(vector<vector<char>>& grid, int i, int j, int& m, int& n) {
        for (int a = 0; a < 4; a++) {
            int nx = i + move[a], ny = j + move[a + 1];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                if (grid[nx][ny] == '1') {
                    grid[nx][ny] = '0';
                    DFS(grid, nx, ny, m, n);
                }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    DFS(grid, i, j, m, n);
                    count++;
                }

        return count;
    }
};
