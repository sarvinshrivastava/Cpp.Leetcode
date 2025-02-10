class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;

        while (i < j) {
            int m = i + (j - i) / 2;

            if (m % 2 == 0) {
                if (m + 1 < nums.size() && nums[m] == nums[m + 1])
                    i = m + 1;
                else
                    j = m;
            } else {
                if (m - 1 >= 0 && nums[m] == nums[m - 1])
                    i = m + 1;
                else
                    j = m;
            }
        }
        return nums[i];
    }
};
