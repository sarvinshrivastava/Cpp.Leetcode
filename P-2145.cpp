class Solution
{
public:
    int numberOfArrays(vector<int> &diff, int lower, int upper)
    {
        long long minP = 0, maxP = 0, cur = 0;

        for (int d : diff)
        {
            cur += d;
            minP = min(minP, cur);
            maxP = max(maxP, cur);
        }

        long long minS = lower - minP, maxS = upper - maxP, count = maxS - minS + 1;
        return max(0LL, count);
    }
};
