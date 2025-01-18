class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        dq.push_front({0, 0});
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; ++k) {
                int nx = x + dir[k].first;
                int ny = y + dir[k].second;

                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int ncst = cost[x][y] + (grid[x][y] != k + 1 ? 1 : 0);

                    if (ncst < cost[nx][ny]) {
                        cost[nx][ny] = ncst;

                        if (grid[x][y] == k + 1)
                            dq.push_front({nx, ny});
                        else
                            dq.push_back({nx, ny});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};
