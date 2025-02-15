class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp (s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;

        for (int i = 1; i < s.size(); ++i) {
            int x = 0, y = i;

            while (x < s.size() && y < s.size()) {
                if (s[x] == s[y])
                    dp[x][y] = 2 + dp[x + 1][y - 1];
                else
                    dp[x][y] = max(dp[x][y - 1], dp[x + 1][y]);

                x++; y++;
            }
        }

        return dp[0][s.size() - 1];
    }
};
