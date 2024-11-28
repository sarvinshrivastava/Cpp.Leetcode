class Solution {
    #define tri pair<int, pair<int, int>>

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dir[] = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        priority_queue <tri, vector<tri>, greater<tri>> minHeap;

        minHeap.push({0,{0,0}}); visited[0][0] = true;

        while (!minHeap.empty()) {
            tri temp = minHeap.top();
            minHeap.pop();

            int cost = temp.first, x = temp.second.first, y = temp.second.second;

            if (x == m - 1 && y == n - 1) return cost;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dir[i], ny = y + dir[i + 1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    minHeap.push({cost + grid[nx][ny],{nx, ny}});
                }
            }
        }

        return 0;
    }
};
