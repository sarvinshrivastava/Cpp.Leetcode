class Solution
{
public:
    long long res = -1;
    unordered_map<int, unordered_map<int, unordered_set<long long>>> dp;

    void dfs(const vector<int> &nums, int idx, long long maxLim, long long curProd, int curAltSum, int kSum, bool isEvenIdx, bool started)
    {
        if (curProd > maxLim)
            return;

        if (idx == nums.size())
        {
            if (started && curAltSum == kSum)
            {
                res = max(res, curProd); // allow 0
            }
            return;
        }

        // Memoization
        if (dp[idx][curAltSum].count(curProd))
            return;
        dp[idx][curAltSum].insert(curProd);

        // Skip
        dfs(nums, idx + 1, maxLim, curProd, curAltSum, kSum, isEvenIdx, started);

        // Take current element
        int sign = isEvenIdx ? 1 : -1;
        long long nextProd = started ? curProd * (long long)nums[idx] : (long long)nums[idx];
        int nextAltSum = curAltSum + sign * nums[idx];

        dfs(nums, idx + 1, maxLim, nextProd, nextAltSum, kSum, !isEvenIdx, true);
    }

    int maxProduct(vector<int> &nums, int k, int limit)
    {
        res = -1;
        dp.clear();

        dfs(nums, 0, (long long)limit, 1LL, 0, k, true, false);
        return (int)res;
    }
};
