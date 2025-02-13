class Solution {
public:
    int count = 0, cntObs = 0;
    vector<pair<int, int>> move = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void pathFinder(vector<vector<int>>& grid, vector<vector<bool>>& hasWalked, int& x, int& y, int& m, int& n, int cnt) {
        if (grid[x][y] == 2 && cnt == n * m - 1 - cntObs) {
            count++;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + move[i].first, ny = y + move[i].second;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                if (hasWalked[nx][ny] != true && grid[nx][ny] != -1) {
                    hasWalked[nx][ny] = true;
                    cnt++;
                    pathFinder(grid, hasWalked, nx, ny, m, n, cnt);
                    cnt--;
                    hasWalked[nx][ny] = false;
                }
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int i, j, m = grid.size(), n = grid[0].size(), sx, sy;
        vector<vector<bool>> hasWalked(m, vector<bool>(n, false));

        for (i = 0; i < m; ++i)
            for (j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
        hasWalked[i][j] = true;
                    sx = i; sy = j;
                }
        else if (grid[i][j] == -1)
            cntObs++;

        pathFinder(grid, hasWalked, sx, sy, m, n, 0);

        return count;
    }
};
