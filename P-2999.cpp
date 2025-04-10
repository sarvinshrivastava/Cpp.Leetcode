class Solution {
public:
    long long dp[20][2];
    bool memo[20][2];

    long long dfs(int pos, int tight, const vector<int>& ds, int limit) {
        if (pos == ds.size())
            return 1;

        if (memo[pos][tight])
            return dp[pos][tight];

        long long ans = 0;
        int up = (tight ? ds[pos] : limit);
        for (int d = 0; d <= up; d++) {
            if (d > limit) break;
            int newTight = tight && (d == up);
            ans += dfs(pos + 1, newTight, ds, limit);
        }

        memo[pos][tight] = true;
        dp[pos][tight] = ans;
        return ans;
    }

    long long countUpTo(long long X, int limit) {
        if (X < 0) return 0;
        string s = to_string(X);
        vector<int> ds;
        for (char c : s)
            ds.push_back(c - '0');
        memset(dp, 0, sizeof(dp));
        memset(memo, 0, sizeof(memo));
        return dfs(0, 1, ds, limit);
    }

    long long countInRange(long long L, long long R, int limit) {
        return countUpTo(R, limit) - countUpTo(L - 1, limit);
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        long long s_val = stoll(s);
        int d = s.size();

        long long T = 1;
        for (int i = 0; i < d; i++)
            T *= 10;

        if (s_val > finish) return 0;

        long long lowP;
        if (start <= s_val)
            lowP = 0;
        else
            lowP = (start - s_val + T - 1) / T;

        long long highP = (finish - s_val) / T;

        if (lowP > highP)
            return 0;

        long long result = countInRange(lowP, highP, limit);
        return result;
    }
};
