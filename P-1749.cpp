class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx = -1, curSum = 0;

        for (auto n : nums) {
            curSum = max(n, curSum + n);
            mx = max(mx, curSum);
        }

        int mn = INT_MAX; curSum = 0;
        for (auto n : nums) {
            curSum = min(n, curSum + n);
            mn = min(mn, curSum);
        }

        return max(mx, abs(mn));
    }
};
