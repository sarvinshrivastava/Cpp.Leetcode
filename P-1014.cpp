class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int len = values.size();
        vector<int> dp(len, 0);

        for (int i = 0; i < len; ++i)
            dp[i] = values[i] - i;

        for (int i = len - 2; i >= 0; --i)
            dp[i] = max(dp[i + 1], dp[i]);

        int mx = -1;
        for (int i = 0; i < len - 1; ++i) {
            mx = max(mx, values[i] + i + dp[i + 1]);
        }

        return mx;
        /*
         * i/p [8, 1, 5, 2, 6]
         * o/p 11
         * dp [8, 0, 3, -1, 1]
         * pst [8, 3, 3, 1, 1]
         */
    }
};
