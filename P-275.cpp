class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size(), l = 0, h = len - 1, res = 0;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (citations[m] >= len-m) {
                res = len - m;
                h = m - 1;
            }
            else
                l = m + 1;
        }

        return res;
    }
};
