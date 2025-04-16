class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        long long pairCnt = 0, cnt = 0;
        int i = 0, n = nums.size();

        for (int j = 0; j < n; ++j) {
            long long prevFreq = freq[nums[j]];
            pairCnt -= (prevFreq * (prevFreq - 1)) / 2;

            freq[nums[j]]++;
            long long newFreq = freq[nums[j]];
            pairCnt += (newFreq * (newFreq - 1)) / 2;

            while (pairCnt >= k) {
                cnt += n - j;

                long long prev = freq[nums[i]];
                pairCnt -= (prev * (prev - 1)) / 2;

                freq[nums[i]]--;
                long long now = freq[nums[i]];
                pairCnt += (now * (now - 1)) / 2;

                i++;
            }
        }

        return cnt;
    }
};
