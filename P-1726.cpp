class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productMap;

        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                productMap[nums[i] * nums[j]]++;

        int combinations = 0;
        for (auto x : productMap)
            if (x.second > 1)
                combinations += x.second * (x.second - 1) * 4;

        return combinations;
    }
};
