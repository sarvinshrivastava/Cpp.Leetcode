class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int i;

        for (i = nums.size() - 1; i >= 0; --i)
        {
            int x = nums[i];
            map[x]++;

            if (map[x] > 1)
                break;
        }

        return ceil((i + 1) / 3.0);
    }
};