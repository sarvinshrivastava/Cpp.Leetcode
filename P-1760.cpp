class Solution {
public:
    bool canDivide(int maxBalls, vector<int>& nums, int maxOperations) {
        int operations = 0;
        for (int num : nums) {
            if (num > maxBalls) {
                operations += (num - 1) / maxBalls;
            }
        }
        return operations <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(mid, nums, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
