class Solution {
public:
    int decode(string& s, vector<int>& dp, int idx) {
        if (idx >= s.size())
            return 1;

        if (s[idx] == '0')
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int a;
        a = decode(s, dp, idx + 1);
        if (idx + 1 < s.size() && stoi(s.substr(idx, 2)) < 27) {
            a = a + decode(s, dp, idx + 2);
        }

dp[idx] = a;
        return dp[idx];
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);

        return decode(s, dp, 0);
    }
};
