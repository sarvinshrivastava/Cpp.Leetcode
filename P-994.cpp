class Solution {
struct tri {
    int x, y, time;
};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), freshOrangeCount = 0;

        queue<tri> q;

        int moves[5] = {0, 1, 0, -1, 0};

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2)
                    q.push({i, j, 0});

                if (grid[i][j] == 1)
                    freshOrangeCount++;
            }

        if (freshOrangeCount == 0) return 0;

        int time, freshCnt = 0;
        while (!q.empty()) {
            auto [x, y, t] = q.front();
            q.pop();
            time = t;

            for (int i = 0; i < 4; ++i) {
                int nx = x + moves[i], ny = y + moves[i + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    freshCnt++;
                    q.push({nx, ny, t + 1});
                    grid[nx][ny] = 2;
                }
            }
        }

        return (freshOrangeCount == freshCnt) ? time : -1;
    }
};
