class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int curSum = 0, maxSum = 0, prevNum = -1;

        for (auto x : nums) {
            if (x > prevNum) {
                curSum += x;
                prevNum = x;
            }
            else {
                maxSum = (maxSum > curSum) ? maxSum : curSum;
                curSum = x;
                prevNum = x;
            }

            // cout << x << "::" << curSum << " " << maxSum << endl;
        }

        return (maxSum > curSum) ? maxSum : curSum;
    }
};
