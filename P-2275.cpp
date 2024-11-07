class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int len = candidates.size(), maxf = 0;

        for (int i = 0;  i < 32; i++) {
            int freq = 0;
            for (auto x : candidates) {
                if (x & (1 << i)) freq++;
            }
            maxf = max(maxf, freq);
        }

        return maxf;
    }
};
