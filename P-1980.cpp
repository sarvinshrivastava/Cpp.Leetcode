class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> elements;
        int bitCount = nums[0].size();

        for (auto& n : nums) {
            int sum = 0;
            for (int idx = 0; idx < bitCount; idx++) {
                if (n[idx] == '1')
                    sum += (1 << (bitCount - 1 - idx));
            }
            elements.insert(sum);
        }

        int maxNum = (1 << bitCount);
        int missingNum = 0;

        for (int i = 0; i < maxNum; ++i) {
            if (elements.find(i) == elements.end()) {
                missingNum = i;
                break;
            }
        }

        string res = bitset<16>(missingNum).to_string();
        return res.substr(16 - bitCount);
    }
};
