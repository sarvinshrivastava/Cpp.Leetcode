class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int len = nums.size(), cnt = 0;

        for (int i = 0; i < len; ++i)
            for (int j = i + 1; j < len; ++j)
                if (nums[i] == nums[j] && i * j % k == 0)
                    cnt++;

        return cnt;
    }
};
