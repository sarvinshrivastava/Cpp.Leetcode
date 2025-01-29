class Solution {
public:
    int fishCnt(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
                int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;

        return grid[i][j] + fishCnt(grid, visited, i, j + 1) +
               fishCnt(grid, visited, i, j - 1) +
               fishCnt(grid, visited, i + 1, j) +
               fishCnt(grid, visited, i - 1, j);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mFishCnt = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    mFishCnt =
                        max(mFishCnt, fishCnt(grid, visited, i, j));
                }
            }
        }

        return mFishCnt;
    }
};
