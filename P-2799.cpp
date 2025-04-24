class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        unordered_set<int> set;

        for (auto n : nums)
            set.insert(n);

        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            unordered_set<int> nw;

            for (int j = i; j < nums.size(); ++j)
            {
                nw.insert(nums[j]);

                if (nw.size() == set.size())
                {
                    count += nums.size() - j;
                    // cout << i << " " << j << " " << count << endl;
                    break;
                }
            }
        }

        return count;
    }
};