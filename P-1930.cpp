class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int len = s.size(), sum = 0;
        vector <pair<int, int>> loc (26, pair<int, int>({-1, -1}));

        for (int i = 0; i < len; ++i) {
            int ind = s[i] - 'a';

            if (loc[ind].first == -1)
                loc[ind].first = i;

            loc[ind].second = i;
        }

        for (int i = 0; i < 26; ++i) {
            if (loc[i].first == loc[i].second || loc[i].first == -1)
                continue;

            vector <bool> set (26, false);
            for (int j = loc[i].first + 1; j < loc[i].second; ++j)
                set.at(s[j] - 'a') = true;

            sum += count(set.begin(), set.end(), true);
        }

        return sum;
    }
};
