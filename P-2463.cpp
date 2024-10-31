class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e18));

        dp[0][0] = 0;

        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 0;
            for (int i = 1; i <= n; ++i) {
                dp[i][j] = dp[i][j - 1];

                long long distance = 0;
                for (int k = 1; k <= min(i, factory[j - 1][1]); ++k) {
                    distance += abs(robot[i - k] - factory[j - 1][0]);
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + distance);
                }
            }
        }

        return dp[n][m];
    }
};
