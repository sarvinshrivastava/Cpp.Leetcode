class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size(), mxLen = 1, eIdx = 0;
        vector<int> dp(n, 1), prev(n, -1);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > mxLen)
            {
                mxLen = dp[i];
                eIdx = i;
            }
        }

        vector<int> res;
        int curIdx = eIdx;
        while (curIdx != -1)
        {
            res.push_back(nums[curIdx]);
            curIdx = prev[curIdx];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};