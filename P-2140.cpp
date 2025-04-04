class Solution {
public:
    unordered_map<int, long long> memo;

    long long reccurse(vector<vector<int>>& qs, int idx) {
        if (idx >= qs.size())
            return 0;

        if (memo.count(idx))
            return memo[idx];

        // do
        long long do_ = qs[idx][0] + reccurse(qs, idx + qs[idx][1] + 1);
        // skip
        long long skip_ = reccurse(qs, idx + 1);

        memo[idx] = max(do_, skip_);
        return memo[idx];
    }

    long long mostPoints(vector<vector<int>>& questions) {
        return reccurse(questions, 0);
    }
};
