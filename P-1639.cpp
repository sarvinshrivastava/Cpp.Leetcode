class Solution {
public:
    long getWords(vector<string>& words, string& target, int wIdx,
                  int tIdx, vector<vector<int>>& dp,
                  vector<vector<int>>& charFreq) {
        if (tIdx == target.size())
            return 1;
        if (wIdx == words[0].size() || words[0].size() - wIdx < target.size() - tIdx)
            return 0;

        if (dp[wIdx][tIdx] != -1)
            return dp[wIdx][tIdx];

        long cWays = 0;
        int curPos = target[tIdx] - 'a';
        cWays += getWords(words, target, wIdx + 1, tIdx, dp, charFreq);
        cWays += charFreq[wIdx][curPos] *
                     getWords(words, target, wIdx + 1, tIdx + 1, dp, charFreq);

        return dp[wIdx][tIdx] = cWays % 1000000007;
    }

    int numWays(vector<string>& words, string target) {
        int wlen = words[0].size(), tlen = target.size();
        vector<vector<int>> dp(wlen, vector<int>(tlen, -1));
        vector<vector<int>> charFreq(wlen, vector<int>(26, 0));

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < wlen; j++) {
                ++charFreq[j][words[i][j] - 'a'];
            }
        }
        return getWords(words, target, 0, 0, dp, charFreq);
    }
};
