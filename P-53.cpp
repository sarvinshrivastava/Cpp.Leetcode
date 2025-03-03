class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, curSum = 0;

        for (int x : nums) {
            curSum = max(x, curSum + x);
            maxSum = max(maxSum, curSum);
        }

        return maxSum;
    }
};
