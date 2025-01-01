class Solution {
public:
    int maxScore(string s) {
        int l, r = 0, len = s.size();

        for (int i = 1; i < len; ++i)
            if (s[i] - '0' == 1) ++r;

        l = (s[0] - '0' == 0) ? 1 : 0;

        int mx = l + r;
        for (int i = 1; i < len - 1; ++i) {
            int e = s[i] - '0';

            if (e == 0) l++;
            else r--;

            mx = max(mx, l + r);
        }

        return mx;
    }
};
