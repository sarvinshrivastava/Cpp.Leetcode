class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> fst, snd;
        int n = nums.size();

        for (auto& num : nums)
            snd[num]++;

        for (int idx = 0; idx < n; idx++) {
            int num = nums[idx];
            snd[num]--;
            fst[num]++;

            if (fst[num] * 2 > idx + 1 &&
                snd[num] * 2 > n - idx - 1) {
                return idx;
            }
        }

        return -1;
    }
};