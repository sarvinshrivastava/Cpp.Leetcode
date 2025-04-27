class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i + 2 < nums.size(); ++i)
            if ((float)nums[i + 1] / 2 == (float)(nums[i] + nums[i + 2]))
                ++count;

        return count;
    }
};