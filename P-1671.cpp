class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1), LDS(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[j] < nums[i]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        int minRemovals = n;

        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) {
                int mountainLen = LIS[i] + LDS[i] - 1;
                minRemovals = min(minRemovals, n - mountainLen);
            }
        }

        return minRemovals;
    }
};
