class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector <int> preMin(len), sufMax(len);

        preMin[0] = prices[0];
        for (int i = 1; i < len; ++i)
            preMin[i] = min (preMin[i - 1], prices[i]);

        sufMax[len - 1] = prices[len - 1];
        for (int i = len - 2; i >= 0; --i)
            sufMax[i] = max (sufMax[i + 1], prices[i]);

        int mx = -1;
        for (int i = 0; i < len; ++i)
            mx = max (mx, sufMax[i] - preMin[i]);

        return mx;
    }
};
