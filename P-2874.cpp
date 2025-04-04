class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefixMax(len), suffixMax(len);
        
        prefixMax[0] = nums[0];
        for (int i = 1; i < len; ++i)
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);

        suffixMax[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; --i)
            suffixMax[i] = max(nums[i], suffixMax[i + 1]);

        long long res = 0;
        for (int i = 1; i < len - 1; ++i)
            res = max(res, (long long)(prefixMax[i - 1] - nums[i]) * suffixMax[i + 1]);
        
        return res;
    }
};