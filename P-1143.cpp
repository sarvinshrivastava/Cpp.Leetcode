class Solution {
public:
    int reccurse (string& s1, string& s2, vector<vector<int>>& dp, int i, int j) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            dp[i][j] = 1 + reccurse(s1, s2, dp, i - 1, j - 1);
        else
            dp[i][j] = max(reccurse(s1, s2, dp, i - 1, j), reccurse(s1, s2, dp, i, j - 1));

        return dp[i][j];

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));

        return reccurse(text1, text2, dp, text1.size() - 1, text2.size() - 1);
    }
};
