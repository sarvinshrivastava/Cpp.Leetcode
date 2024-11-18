class Solution {
public:
    int len;

    int cycleSumP(const vector<int>& num, int k, int start) {
        int sum = 0;

        for (int i = 1; i <= k; ++i) {
            sum += num[(start + i) % len];
        }

        return sum;
    }

    int cycleSumN(const vector<int>& num, int k, int start) {
        int sum = 0;

        for (int i = 1; i <= -k; ++i) {
            int idx = (start - i + len) % len;
            sum += num[idx];
        }

        return sum;
    }

    vector<int> decrypt(vector<int>& code, int k) {
        len = code.size();
        vector<int> ans(len);

        if (k == 0) {
            fill(ans.begin(), ans.end(), 0);
        } else if (k > 0) {
            for (int i = 0; i < len; i++) {
                ans[i] = cycleSumP(code, k, i);
            }
        } else {
            for (int i = 0; i < len; i++) {
                ans[i] = cycleSumN(code, k, i);
            }
        }

        return ans;
    }
};
