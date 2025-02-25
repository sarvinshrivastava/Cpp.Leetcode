class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7, n = arr.size();

        for (auto& ele : arr)
            ele &= 1;

        vector<int> edp(n, 0), odp(n, 0);

        if (arr[n - 1] == 0)
            edp[n - 1] = 1;
        else
            odp[n - 1] = 1;

        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] == 1) {
                odp[i] = (1 + edp[i + 1]) % MOD;
                edp[i] = odp[i + 1];
            }
            else {
                edp[i] = (1 + edp[i + 1]) % MOD;
                odp[i] = odp[i + 1];
            }
        }

        int cnt = 0;
        for (auto k : odp) {
            cnt += k;
            cnt %= MOD;
        }

        return cnt;
    }
};
