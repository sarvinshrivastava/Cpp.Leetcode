class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int lastInvalid = -1, lastMinPos = -1, lastMaxPos = -1;

        for (int i = 0; i < (int)nums.size(); ++i) {
            int v = nums[i];

            if (v < minK || v > maxK)
                lastInvalid = i;
            if (v == minK)
                lastMinPos = i;
            if (v == maxK)
                lastMaxPos = i;

            int validStart = min(lastMinPos, lastMaxPos);

            if (validStart > lastInvalid)
                result += (validStart - lastInvalid);
        }

        return result;
    }
};