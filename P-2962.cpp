class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size(), mx = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        int cnt = 0, j = 0;

        for (int i = 0; i < n; ++i)
        {

            while (j < n && cnt < k)
            {
                if (nums[j] == mx)
                    ++cnt;
                ++j;
            }

            if (cnt < k)
                break;
            ans += (n - (j - 1));
            if (nums[i] == mx)
                --cnt;
        }
        return ans;
    }
};
