class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            unordered_map<int, int> freq;
    
            for (auto n : nums)
                freq[n]++;
    
            vector<int> result;
            for (auto [key, val] : freq)
                if (val > nums.size() / 3)
                    result.push_back(key);
    
            return result;
        }
    };