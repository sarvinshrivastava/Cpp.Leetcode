class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        long long maxSum = 0, currentSum = 0;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            um[nums[i]]++;
            currentSum += nums[i];
        }

        if (um.size() == k) {
            maxSum = currentSum;
        }

        for (int i = k; i < n; i++) {
            um[nums[i]]++;
            currentSum += nums[i];
            um[nums[i - k]]--;
            currentSum -= nums[i - k];

            if (um[nums[i - k]] == 0) {
                um.erase(nums[i - k]);
            }

            if (um.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};
