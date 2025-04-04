class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int result = 0;

        for (int row = 0; row < grid.size(); row++)
            for (int col = 0; col < grid[0].size(); col++)
                nums.push_back(grid[row][col]);

        int len = nums.size();

        nth_element(nums.begin(), nums.begin() + len / 2, nums.end());

        int fcn = nums[len / 2];

        for (int n : nums) {
            if (n % x != fcn % x)
                return -1;
            result += abs(fcn - n) / x;
        }

        return result;
    }
};