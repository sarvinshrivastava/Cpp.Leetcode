class Solution {
public:
    int minOperations(vector<int>& nums) {
        int zCnt = 0;

        for (auto x : nums)
            if (x == 0) zCnt++;

        if (zCnt == 0) return 0;
        int cnt = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] == 0) {
                zCnt--;
                cnt++;
                
                if (nums[i + 1] == 0) zCnt--;
                else zCnt++;
                if (nums[i + 2] == 0) zCnt--;
                else zCnt++;

                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
            }
        }

        return (zCnt == 0) ? cnt : -1;
    }
};