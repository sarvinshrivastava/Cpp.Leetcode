class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; ++i) {
            vector <int> freq (n, 0);

            for (int j = 0; j < n; ++j)
                freq[matrix[i][j] - 1]++;

            for (auto f : freq)
                if (f != 1)
                    return false;
        }

        for (int i = 0; i < n; ++i) {
            vector <int> freq (n, 0);

            for (int j = 0; j < n; ++j)
                freq[matrix[j][i] - 1]++;

            for (auto f : freq)
                if (f != 1)
                    return false;
        }

        return true;
    }
};
