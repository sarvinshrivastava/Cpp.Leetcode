#define pip pair<int, pair<int, int>>

class Solution {
public:
    bool isValid(int& x,int& y,int& m,int& n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0;

        vector<vector<bool>> visit(m, vector<bool>(n, false));
        priority_queue<pip, vector<pip>, greater<pip>> heap;

        for (int i = 0; i < m; ++i) {
            heap.push({heightMap[i][0], {i, 0}});
            heap.push({heightMap[i][n - 1], {i, n - 1}});
            visit[i][0] = true;
            visit[i][n - 1] = true;
        }
        for (int j = 0; j < n; ++j) {
            heap.push({heightMap[0][j], {0, j}});
            heap.push({heightMap[m - 1][j], {m - 1, j}});
            visit[0][j] = true;
            visit[m - 1][j] = true;
        }

        int quant = 0, level = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!heap.empty()) {
            auto top = heap.top();
            int x = top.second.first, y = top.second.second;
            int height = top.first;
            heap.pop();

            level = max(level, height);

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny = y + dir[i + 1];

                if (isValid(nx, ny, m, n) && !visit[nx][ny]) {
                    heap.push({heightMap[nx][ny], {nx, ny}});
                    visit[nx][ny] = true;

                    if (heightMap[nx][ny] < level)
                        quant += level - heightMap[nx][ny];
                }
            }
        }

        return quant;
    }
};
