class Solution {
public:
    int tSum = 0;

    int calculateWays(vector<int>& nums, int curIndx, int curSum, int t, vector<vector<int>>& memo)  {
        if (curIndx ==  nums.size()) {
            if (curSum == t) return 1;
            else return 0;
        }
        else {
            if (memo[curIndx][curSum + tSum] != numeric_limits<int>::min()) {
                return memo[curIndx][curSum + tSum];
            }

            int add = calculateWays(nums, curIndx + 1, curSum + nums[curIndx], t, memo);
            int sub = calculateWays(nums, curIndx + 1, curSum - nums[curIndx], t, memo);

            memo[curIndx][curSum + tSum] = add + sub;

            return memo[curIndx][curSum + tSum];
        }

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        tSum = accumulate (nums.begin(), nums.end(), 0);

        vector<vector<int>> memo(nums.size(), vector<int>(2 * tSum + 1, numeric_limits<int>::min()));

        return calculateWays(nums, 0, 0, target, memo);
    }
};
