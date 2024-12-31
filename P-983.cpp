class Solution {
public:
    unordered_set<int> travelNeed;

    int solve(vector<int>& dp, vector<int>& days, vector<int>& cst, int curDate) {
        if (curDate > days[days.size() - 1]) return 0;

        if (travelNeed.find(curDate) == travelNeed.end())
            return solve (dp, days, cst, curDate + 1);

        if (dp[curDate] != -1) return dp[curDate];

        int oneDay = cst[0] + solve(dp, days, cst, curDate + 1);
        int sevenDay = cst[1] + solve(dp, days, cst, curDate + 7);
        int thirtyDay = cst[2] + solve(dp, days, cst, curDate + 30);

        return dp[curDate] = min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <int> dp(days[days.size() - 1] + 1, -1);

        for (auto d : days) travelNeed.insert(d);

        return solve(dp, days, costs, 1);
    }
};
