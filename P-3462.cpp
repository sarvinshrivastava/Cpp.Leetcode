class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        if (k == 0) return 0;

        int m = grid.size(), n = grid[0].size();
        vector <int> selected;

        for (int i = 0; i < m; i++) {
            sort (grid[i].begin(), grid[i].end());
            int cnt = limits[i];

            for (int j = n - 1; j >= 0 && cnt > 0; j--) {
                selected.push_back(grid[i][j]);
                cnt--;
            }
        }

        sort(selected.begin(), selected.end());
        long long sum = 0;
        int i = selected.size() - 1;
        while (k > 0 && i >= 0) {
            sum += selected[i];
            k--;
            i--;
        }

        return sum;
    }
};
