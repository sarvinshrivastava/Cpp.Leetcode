class Solution {
public:
    int count(vector<vector<int>>& grid, int i, int j, int m, int n) {
        int cnt = 0;
        queue<pair<int, int>> loc;
        loc.push({i, j});

        while (!loc.empty()) {
            auto [x, y] = loc.front();
            loc.pop();

            for (int a = 0; a < m; ++a)
                if (grid[a][y] == 1 && a != x) {
                    loc.push({a, y});
                    cnt++;
                    grid[a][y] = -1;
                }
            for (int a = 0; a < n; ++a)
                if (grid[x][a] == 1 && a != y) {
                    loc.push({x, a});
                    cnt++;
                    grid[x][a] = -1;
                }
        }

        return (cnt > 0) ? cnt + 1 : 0;
    }

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    cnt += count(grid, i, j, m, n);
                }

        return cnt;
    }
};
