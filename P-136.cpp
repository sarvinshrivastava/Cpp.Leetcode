class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int, int> freq;

        for (auto x : nums)
            freq[x]++;

        for (auto [key, f] : freq)
            if (f == 1)
                return key;

        return -1;
    }
};
