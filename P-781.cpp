class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int a : answers)
            freq[a]++;

        int total = 0;
        for (auto [x, cnt] : freq) {
            int groups = (cnt + x) / (x + 1);
            total += groups * (x + 1);
        }

        return total;
    }
};
