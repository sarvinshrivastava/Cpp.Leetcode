class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> set;

        for (long n = 1; n <= bound; n *= x) {
            for (long m = 1; m + n <= bound; m *= y) {
                set.insert(n + m);
                if (y == 1) break;
            }
            if (x == 1) break;
        }

        vector<int> res(set.begin(), set.end());
        sort(res.begin(), res.end());

        return res;
    }
};
