class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size() - 1;) {
            if (nums[i] == 0) {
                count++;
                nums.erase (nums.begin() + i);
            }
            else if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                i++;
                count++;
                nums.erase(nums.begin() + i);
            }
            else
                i++;
        }

        nums.insert(nums.end(), count, 0);
        return nums;
    }
};
