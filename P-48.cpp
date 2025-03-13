class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < m; ++i)
            for (int j = i + 1; j < m; ++j)
                swap(matrix[i][j], matrix[j][i]);

        // Rowise reverse
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m / 2; ++j)
                swap(matrix[i][j], matrix[i][m - j - 1]);
    }
};