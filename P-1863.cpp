class Solution
{
public:
    int sum = 0;

    void reccurse(vector<int> &nums, int idx, int cur)
    {
        if (idx == nums.size())
        {
            sum += cur;
            return;
        }

        reccurse(nums, idx + 1, cur ^ nums[idx]);
        reccurse(nums, idx + 1, cur);
    }

    int subsetXORSum(vector<int> &nums)
    {
        reccurse(nums, 0, 0);

        return sum;
    }
};