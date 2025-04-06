class Solution
{
public:
    pair<int, bool> validate(vector<int> &nums)
    {
        bool flag = true;
        int mSum = INT_MAX;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
                flag = false;

            mSum = min(mSum, nums[i] + nums[i + 1]);
        }
        return {mSum, flag};
    }

    int minimumPairRemoval(vector<int> &nums)
    {
        int count = 0;

        while (nums.size() > 1)
        {
            auto [x, f] = validate(nums);
            // cout << "x:" << x << " f:" << f << endl;
            if (f == true)
                return count;
            count++;

            for (int i = 0; i < nums.size() - 1; ++i)
                if (x == nums[i] + nums[i + 1])
                {
                    nums.erase(nums.begin() + i + 1);
                    nums[i] = x;
                    break;
                }

            // cout << "===========================\n";
            // for (auto e : nums)
            //     cout << e << " ";
            // cout << endl;
        }

        return count;
    }
};