class Solution {
public:
    bool isConsecutive(vector<int>& nums, int start, int size) {
        for (int i = start; i < start + size - 1; i++) {
            if (nums[i + 1] - nums[i] != 1) return false;
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int len = nums.size();

        for (int i = 0; i < len - k + 1; i++) {
            bool isSort = is_sorted(nums.begin() + i, nums.begin() + i + k);

            if (isSort == true){
                bool isCon = isConsecutive(nums, i, k);

                // cout << isSort << " " << isCon << endl;

                if (isCon == true) res.push_back(nums[i + k - 1]);
                else res.push_back(-1);
            }
            else res.push_back(-1);
        }

        return res;
    }
};
