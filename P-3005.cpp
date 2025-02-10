class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> map;

        for (auto n : nums)
            map[n]++;

        int max = -1, sum = 0;
        for (auto m : map) {
            if (max < m.second) {
                max = m.second;
                sum = m.second;
            } else if (max == m.second)
                sum += m.second;
        }

        return sum;
    }
};
