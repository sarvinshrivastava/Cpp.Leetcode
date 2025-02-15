class Solution {
public:
    int cutCnt(string& s, vector<vector<bool>>& isPal, vector<int>& dp, int idx) {
        if (idx >= s.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;
        for (int i = idx; i < s.size(); ++i) {
            if (isPal[idx][i])
                ans= min(ans, cutCnt(s, isPal, dp, i + 1) + 1);
        }

        dp[idx] = ans;
        return dp[idx];
    }

    int minCut(string s) {
        vector<vector<bool>> isPal (s.size(), vector<bool>(s.size(), true));
        vector<int> dp (s.size(), -1);

        for (int i = 1; i < s.size(); ++i) {
            int x = 0, y = i;

            while (x < s.size() && y < s.size()) {
                if (s[x] == s[y])
                    isPal[x][y] = isPal[x + 1][y - 1];
                else
                    isPal[x][y] = false;

                x++; y++;
            }
        }

        // for (int i = 0; i < s.size(); ++i) {
        //     for (auto j : isPal[i])
        //         cout << j << " ";
        //     cout << endl;
        // }

        return cutCnt(s, isPal, dp, 0) - 1;
    }
};
