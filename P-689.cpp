class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        vector<int> left(n, 0), right(n, 0);
        int maxLeft = 0;

        for (int i = k - 1; i < n; ++i) {
            int currentSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
            if (currentSum > prefixSum[maxLeft + k] - prefixSum[maxLeft]) {
                maxLeft = i + 1 - k;
            }
            left[i] = maxLeft;
        }

        int maxRight = n - k;
        for (int i = n - k; i >= 0; --i) {
            int currentSum = prefixSum[i + k] - prefixSum[i];
            if (currentSum >= prefixSum[maxRight + k] - prefixSum[maxRight]) {
                maxRight = i;
            }
            right[i] = maxRight;
        }

        vector<int> result(3, -1);
        int maxSum = 0;

        for (int midStart = k; midStart <= n - 2 * k; ++midStart) {
            int leftIdx = left[midStart - 1];
            int rightIdx = right[midStart + k];
            int totalSum = (prefixSum[leftIdx + k] - prefixSum[leftIdx]) +
                           (prefixSum[midStart + k] - prefixSum[midStart]) +
                           (prefixSum[rightIdx + k] - prefixSum[rightIdx]);
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {leftIdx, midStart, rightIdx};
            }
        }

        return result;
    }
};
