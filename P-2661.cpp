class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), a = m * n;
        unordered_map <int, pair<int, int>> loc;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                loc[mat[i][j]] = {i, j};

        vector <int> rowFreq (m, 0), colFreq(n, 0);
        for (int i = 0; i < a; ++i) {
            auto [x, y] = loc[arr[i]];

            mat[x][y] = -mat[x][y];
            rowFreq[x]++; colFreq[y]++;

            if (rowFreq[x] == n || colFreq[y] == m)
                return i;
        }

        return 0;
    }
};
