class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (j == 0)
                    continue;
                mat[i][j] += mat[i][j - 1];
            }

        for (int j = 0; j < n; j++)
            for (int i = 0; i < m; i++) {
                if (j == 0)
                    continue;
                mat[j][i] += mat[j - 1][i];
            }

        matrix = mat;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = matrix[row2][col2];

        if (row1 > 0)
            ans -= matrix[row1 - 1][col2];

        if (col1 > 0)
            ans -= matrix[row2][col1 - 1];

        if (row1 > 0 && col1 > 0)
            ans += matrix[row1 - 1][col1 - 1];

        return ans;
    }
};
