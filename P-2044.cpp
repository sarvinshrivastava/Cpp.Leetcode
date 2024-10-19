class Solution {
public:
    int res = 0, max = 0;

    int countMaxOrSubsets(vector<int>& nums) {
        for (auto x : nums) max |= x;

        backTrack(nums, 0, 0);

        return res;
    }

    void backTrack (vector <int> & nums, int start, int val) {
        if (val == max) res++;

        for (int i = start; i < nums.size(); i++ ) {
            backTrack(nums, i + 1, val | nums[i]);
        }
    }
};
