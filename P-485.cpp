class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0, mx = -1;

        for (auto x : nums) {
            if (x == 1)
                cur++;
            else {
                mx = max (cur, mx);
                cur = 0;
            }
        }

        return max(mx, cur);
    }
};
