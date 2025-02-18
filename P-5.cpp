class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0) return "";

        vector<vector<bool>> dp(len, vector<bool>(len, false));

        int maxlen = 1, start = 0;

        for (int i = 0; i < len; ++i)
            dp[i][i] = true;

        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }

        for (int subLen = 3; subLen <= len; ++subLen) {
            for (int i = 0; i <= len - subLen; ++i) {
                int j = i + subLen - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxlen = subLen;
                }
            }
        }

        return s.substr(start, maxlen);
    }
};
