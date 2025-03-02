class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0;
        long curr = 0;

        for (int r = 0; r < nums.size(); r++) {
            long t = nums[r];
            curr += t;

            if ((r - l + 1) * t - curr > k) {
                curr -= nums[l];
                l++;
            }
        }

        return nums.size() - l;
    }
};
