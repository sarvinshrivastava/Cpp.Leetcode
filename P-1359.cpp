class Solution {
public:
    long long MOD = 1e9 + 7;

    int countOrders(int n) {
        long long ans = 1;

        for (long i = 2; i <= n; ++i) {
            long long pos = 2 * (i - 1) + 1;
            long long total = ((pos * (pos + 1)) / 2) % MOD;
            ans = ((ans % MOD) * total) % MOD;
        }


        return ans;
    }
};
