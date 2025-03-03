class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        result.reserve(nums.size());

        for (auto x : nums) {
            if (x < pivot)
                result.push_back(x);
        }

        for (auto x : nums) {
            if (x == pivot)
                result.push_back(x);
        }

        for (auto x : nums) {
            if (x > pivot)
                result.push_back(x);
        }

        return result;
    }
};
