class Solution {
public:
    vector <vector <int>> res;

    void swap (vector<int>& nums, int i, int j) {
        auto temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void generate (vector <int>& nums, int idx) {
        if (idx == nums.size() - 1) {
            res.push_back(nums);
            return ;
        }

        for (int i = idx; i < nums.size(); ++i) {
            swap (nums, idx, i);
            generate(nums, idx + 1);
            swap (nums, idx, i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        generate (nums, 0);

        return res;
    }
};
