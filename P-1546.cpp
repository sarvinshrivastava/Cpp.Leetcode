class Solution {
public:
    int maxNonOverlapping(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> prefixSumMap;
        int prefixSum = 0, count = 0;
        prefixSumMap[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            if (prefixSumMap.find(prefixSum - target) != prefixSumMap.end()) {
                count++;
                prefixSumMap.clear();
                prefixSumMap[0] = 1;
                prefixSum = 0;
            }
            prefixSumMap[prefixSum]++;
        }

        return count;
    }
};
