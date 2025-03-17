class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map <int, int> freqMap;

        for (auto c : nums)
            freqMap[c]++;

        int cntPair = 0;
        for (auto [key, cnt] : freqMap) {
            if (cnt & 1 == 1)
                return false;
            
            cntPair += cnt / 2;
        }

        return (cntPair == nums.size() / 2);
    }
};