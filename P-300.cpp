class Solution {
public:
    int length(const vector<int>& nums, int idx, int last,
               vector<vector<int>>& memo) {
        if (idx == nums.size())
            return 0;

        if (memo[idx][last + 1] != -1)
            return memo[idx][last + 1];

        int skip = length(nums, idx + 1, last, memo);

        int take = 0;
        if (last == -1 || nums[idx] > nums[last]) {
            take = 1 + length(nums, idx + 1, idx, memo);
        }

        memo[idx][last + 1] = max(skip, take);
        return memo[idx][last + 1];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size() + 1, -1));
        return length(nums, 0, -1, memo);
    }
};
