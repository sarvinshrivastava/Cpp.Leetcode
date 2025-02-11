class Solution {
public:
    const long MOD = 1e9 + 7;

    int sumSubseqWidths(vector<int>& nums) {
        int len = nums.size();
        long sum = 0;
        vector <long> power (len, 1);

        for (int i = 1; i < len; ++i)
            power[i] = (power[i - 1] * 2) % MOD;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; ++i) {
            sum = (sum + (nums[i] * (power[i] - power[len - i - 1] + MOD)) % MOD) % MOD;
        }

        return (int) sum;
    }
};
