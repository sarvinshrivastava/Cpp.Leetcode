class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> list (n, 0);
        int len = edges.size(), ans, cnt = 0;

        for (int i = 0; i < len; ++i) {
            list[edges[i][1]] = -1;
        }


        for (int i = 0; i < n; ++i) {
            if (list[i] != -1) {
                ans = i;
                ++cnt;
            }

            if (cnt > 1) return -1;
        }

        return ans;
    }
};
