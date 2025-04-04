class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int qCnt = queries.size(), m = grid.size(), n = grid[0].size(), tCnt = m * n;
        int visit = 0;

        vector<int> result(qCnt);
        vector<int> threshold(tCnt + 1);
        vector<vector<int>> minVal(m, vector<int>(n, INT_MAX));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minHeap;

        minVal[0][0] = grid[0][0];
        minHeap.push({grid[0][0], 0, 0});

        while (!minHeap.empty()) {
            array<int, 3> cur = minHeap.top();

            minHeap.pop();
            threshold[++visit] = cur[0];

            for (auto& dir : dirs) {
                int nRow = cur[1] + dir[0], nCol = cur[2] + dir[1];

                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && minVal[nRow][nCol] == INT_MAX) {
                    minVal[nRow][nCol] = max(cur[0], grid[nRow][nCol]);

                    minHeap.push({minVal[nRow][nCol], nRow, nCol});
                }
            }
        }

        for (int i = 0; i < qCnt; i++) {
            int thresh = queries[i], l = 0, r = tCnt;

            while (l < r) {
                int mid = l + (r - l + 1) / 2;

                if (threshold[mid] < thresh)
                    l = mid;
                else
                    r = mid - 1;
            }

            result[i] = l;
        }

        return result;
    }
};
