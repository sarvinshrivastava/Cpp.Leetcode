class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> preX, ans;
        int nlen = nums.size();

        preX.push_back(nums[0]);
        for (int i = 1; i < nlen; i++)
            preX.push_back(nums[i] ^ preX[i - 1]);

        int mask = (1 << maximumBit) - 1;
        for (int i = nlen - 1; i >= 0; i--)
            ans.push_back(preX[i] ^ mask);

        return ans;
    }
};
