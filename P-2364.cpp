class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long bad_pairs = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            int good_pairs = map[i - nums[i]];
            bad_pairs += i - good_pairs;
            map[i - nums[i]] = good_pairs + 1;
        }


        return bad_pairs;
    }
};
