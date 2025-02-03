class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = nums.size(), prevNum = -1, maxIncCnt = 0, curCnt = 0;

        for (int i = 0; i < len; ++i) {
            int x = nums[i];
            if (prevNum < x)
                curCnt++;
            else {
                maxIncCnt = max(maxIncCnt, curCnt);
                curCnt = 1;
            }
            prevNum = x;
        }
        maxIncCnt = max(maxIncCnt, curCnt);

        int maxDecCnt = 0;
        curCnt = 0; prevNum = 51;
        for (auto x: nums) {
            if (prevNum > x)
                curCnt++;
            else {
                maxDecCnt = max(maxDecCnt, curCnt);
                curCnt = 1;
            }
            prevNum = x;
        }
        maxDecCnt = max(maxDecCnt, curCnt);

        return max(maxIncCnt, maxDecCnt);
    }
};
