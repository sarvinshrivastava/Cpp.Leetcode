class Solution {
public:
    int search(int ht, vector<pair<int, int>>& monoStk) {
        int l = 0;
        int r = monoStk.size() - 1;
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (monoStk[m].first > ht) {
                ans = max(ans, m);
                l = m + 1;
            } else
                r = m - 1;
        }
        return ans;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {

        int qlen = queries.size(), hlen = heights.size();
        vector<pair<int, int>> monoStk;
        vector<int> res(qlen, -1);
        vector<vector<pair<int, int>>> newQ(hlen);

        for (int i = 0; i < qlen; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (heights[b] > heights[a] || a == b)
                res[i] = b;
            else
                newQ[b].push_back({heights[a], i});
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStkS = monoStk.size();
            for (auto& [a, b] : newQ[i]) {
                int pos = search(a, monoStk);
                if (pos < monoStkS && pos >= 0)
                    res[b] = monoStk[pos].second;
            }
            while (!monoStk.empty() && monoStk.back().first <= heights[i])
                monoStk.pop_back();
            monoStk.push_back({heights[i], i});
        }
        return res;
    }
};
