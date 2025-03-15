class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSumCnt;
        preSumCnt[0] = 1;

        int cSum = 0, cnt = 0;

        for (int num : nums) {
            cSum += num;

            if (preSumCnt.count(cSum - k))
                cnt += preSumCnt[cSum - k];

            preSumCnt[cSum]++;
        }

        return cnt;
    }
};