class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, st = -1, end;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                st = m;
            if (nums[m] >= target)
                r = m - 1;
            else
                l = m + 1;
        }

        if (st == -1) return {-1, -1};

        l = 0; r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
                end = m;
            if (nums[m] <= target)
                l = m + 1;
            else
                r = m - 1;
        }

        return {st, end};
    }
};