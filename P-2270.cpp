// class Solution {
// public:
//     int waysToSplitArray(vector<int>& nums) {
//         int len = nums.size();
//         vector <long long> preSum (len), postSum(len);

//         preSum[0] = nums[0];
//         postSum[len - 1] = nums[len - 1];
//         for (int i = 1; i < len; ++i)
//             preSum[i] = preSum[i - 1] + nums[i];
//         for (int i = len - 2; i >= 0; --i)
//             postSum[i] = postSum[i + 1] + nums[i];

//         int cnt = 0;
//         for (int i = 0; i < len - 1; ++i)
//             if (preSum[i] >= postSum[i + 1]) ++cnt;

//         return cnt;
//     }
// };

class Solution {
public:
  int waysToSplitArray(vector<int>& nums) {
      int len = nums.size();
      long long totalSum = 0;

      for (int num : nums) {
          totalSum += num;
      }

      long long prefixSum = 0;
      int count = 0;

      for (int i = 0; i < len - 1; ++i) {
          prefixSum += nums[i];
          long long suffixSum = totalSum - prefixSum;

          if (prefixSum >= suffixSum) {
              ++count;
          }
      }

      return count;
  }
};
