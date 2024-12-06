class Solution {
public:
    int len;

    bool find(vector<int>& nums, int k) {
        int i = 0, j = len - 1;

        while (i <= j) {
            int m = i + (j - i) / 2;

            if (nums[m] == k)
                return true;
            else if (nums[m] > k)
                j = m - 1;
            else
                i = m + 1;
        }

        return false;
    }

    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        len = banned.size();

        vector<int> notin;
        for (int i = 1; i <= n; ++i)
            if (i <= maxSum && !find(banned, i))
                notin.push_back(i);

        if (notin.empty())
            return 0;

        int currSum = notin[0], maxCnt = 0;
        len = notin.size();
        for (int i = 0, j = 0; j < len;) {
            if (currSum <= maxSum) {
                maxCnt = max(maxCnt, j - i + 1);
                ++j;
                if (j < len)
                    currSum += notin[j];
            } else {
                currSum -= notin[i];
                ++i;
            }
        }

        return maxCnt;
    }
};
