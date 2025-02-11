class Solution {
public:
    vector <vector <int>> subset;

    void generate(vector <int>& temp, vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            subset.push_back(temp);
            return ;
        }

        temp.push_back(nums[idx]);
        generate(temp, nums, idx + 1);
        temp.pop_back();
        generate(temp, nums, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        generate(temp, nums, 0);
        return subset;
    }
};
