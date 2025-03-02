class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int max = -1;
        if (nums.size() == k) {
            for (auto num : nums)
                if (num > max)
                    max = num;

            return max;
        }

        unordered_map < int, int > map;

        for (auto n : nums)
            map[n]++;

        if (k == 1) {
            for (auto [num, freq] : map)
                if (freq == 1 && max < num)
                        max = num;
        }
        else {
            if (map[nums.front()] == 1 && max < nums.front())
                max = nums.front();
            if (map[nums.back()] == 1 && max < nums.back())
                max = nums.back();
        }

        return max;
    }
};
