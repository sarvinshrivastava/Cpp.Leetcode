class Solution {
public:
    vector<vector<int>> subset;

    void generate(vector<int>& temp, vector<int>& nums, vector<int>& freq, int idx) {
        if (idx == nums.size()) {
            subset.push_back(temp);
            return;
        }

        generate(temp, nums, freq, idx + 1);

        for (int i = 0; i < freq[idx]; ++i) {
            temp.push_back(nums[idx]);
            generate(temp, nums, freq, idx + 1);
        }

        for (int i = 0; i < freq[idx]; ++i) {
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        subset.clear();

        sort(nums.begin(), nums.end());

        vector<int> uniqueNums, freq;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                uniqueNums.push_back(nums[i]);
                freq.push_back(1);
            } else {
                freq.back()++;
            }
        }

        vector<int> temp;
        generate(temp, uniqueNums, freq, 0);
        return subset;
    }
};
