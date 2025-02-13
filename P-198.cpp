class Solution {
public:

    int findMax(vector<int>& nums, vector<int>& mem, int idx) {
        if (idx >= nums.size())
            return 0;

        if (mem[idx] != -1)
            return mem[idx];

        mem[idx] = max (findMax(nums, mem, idx + 2) + nums[idx], findMax(nums, mem, idx + 1));
        return mem[idx];
    }

    int rob(vector<int>& nums) {
        int sum = 0, len = nums.size();
        vector<int> mem(len, -1);

        return findMax(nums, mem, 0);
    }
};
