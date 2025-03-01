class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size(); ) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                count++;
            }
            else
                i++;
        }

        nums.insert(nums.end(), count, 0);
    }
};
