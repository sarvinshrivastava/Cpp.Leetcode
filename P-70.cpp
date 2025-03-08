class Solution {
public:
    int cnt = 0;
    int reccurse(vector<int>& dp, int n, int cur) {
        if (cur >= n)
            return 1;

        if (dp[cur] != -1)
            return dp[cur];

        int a = reccurse(dp, n, cur + 1);
        if (cur + 2 <= n)
            a += reccurse(dp, n, cur + 2);
        dp[cur] = a;
        return dp[cur];
    }

    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return reccurse(dp, n, 0);
    }
};
