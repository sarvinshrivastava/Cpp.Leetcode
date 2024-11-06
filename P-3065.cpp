class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int c = 0;
        for (auto x : nums) {
            if (k > x) c++;
        }
        return c;
    }
};
