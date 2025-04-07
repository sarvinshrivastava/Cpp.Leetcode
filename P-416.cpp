class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        long sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1 == 1)
            return false;

        int target = sum / 2;
        vector<int> dp(target + 1, false);
        dp[0] = true;

        for (auto x : nums)
            for (int i = target; i >= x; --i)
                dp[i] = dp[i] || dp[i - x];

        return dp[target];
    }
};