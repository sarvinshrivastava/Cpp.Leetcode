class Solution
{
public:
    int digSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n)
    {
        unordered_map<int, int> map;

        int mx = -1;
        while (n > 0)
        {
            auto sum = digSum(n);
            ++map[sum];
            mx = max(mx, map[sum]);
            --n;
        }

        int freq = 0;
        for (auto [sum, cnt] : map)
            if (cnt == mx)
                ++freq;

        return freq;
    }
};