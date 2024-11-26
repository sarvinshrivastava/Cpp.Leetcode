class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (trust.empty() && n == 1) return 1;

        vector <int> arr (n + 1, 0);

        for (auto x : trust) {
            arr[x[0]]--;
            arr[x[1]]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (arr[i] == n - 1) return i;
        }

        return -1;
    }
};
