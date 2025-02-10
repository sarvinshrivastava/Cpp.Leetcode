class Solution {
public:
    int kthGrammar(int n, int k) {
        int j = pow(2, n - 1) - 1, i = 0;
        int cur = 0;

        while (i != j) {
            int m = i + (j - i) / 2;

            if (m >= k - 1)
                j = m;
            else {
                cur = 1 - cur;
                i = m + 1;
            }
        }

        return cur;
    }
};
