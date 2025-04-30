class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto n : nums) {
            string tmp = to_string(n);

            if ((tmp.size() & 1) == 0)
                cnt++;
        }

        return cnt;
    }
};