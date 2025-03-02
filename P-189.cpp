class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int var, len = nums.size();
        vector< bool > isVisited(len, false);

        k %= len;

        for (int i = 0; i < len && !isVisited[i]; ++i) {
            int next = (i + k) % len;
            isVisited[i] = true;
            var = nums[i];

            while (next != i) {
                swap(var, nums[next]);
                isVisited[next] = true;
                next = (next + k) % len;
            }
            swap(var, nums[next]);
        }
    }
};
