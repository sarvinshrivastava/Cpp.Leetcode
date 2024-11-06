class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        int prev_seg_max = INT_MIN, curr_seg_max = nums[0];
        int curr_seg_min = nums[0], set_bit_cnt = __builtin_popcount(nums[0]);
        int i = 1;

        while(i < n) {
            while (i < n && set_bit_cnt == __builtin_popcount(nums[i])){
                curr_seg_max = max(curr_seg_max, nums[i]);
                curr_seg_min = min(curr_seg_min, nums[i]);
                i++;
            }
            if (prev_seg_max > curr_seg_min) {
                return false;
            }
            else if (i < n) {
                prev_seg_max = curr_seg_max;
                curr_seg_max = nums[i];
                curr_seg_min = nums[i];
                set_bit_cnt = __builtin_popcount(nums[i]);
            }
        }
        return true;
    }
};
