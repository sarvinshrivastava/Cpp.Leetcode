class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int len = nums.size();

        for (int i = 1; i < len; ++i)
            if (nums[i - 1] % 2 == nums[i] % 2) return false;

        return true;
    }
};
