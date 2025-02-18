class Solution {
public:
    vector<vector<int>> dp;

    int editDistance(string& a, string& b, int i, int j) {
        if (i == a.size())
            return b.size() - j;
        if (j == b.size())
            return a.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j]) {
            dp[i][j] = editDistance(a, b, i + 1, j + 1);
        } else {
            int replaceOp = editDistance(a, b, i + 1, j + 1);
            int deleteOp = editDistance(a, b, i + 1, j);
            int insertOp = editDistance(a, b, i, j + 1);
            dp[i][j] = 1 + min({replaceOp, deleteOp, insertOp});
        }
        return dp[i][j];
    }

    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return editDistance(word1, word2, 0, 0);
    }
};
