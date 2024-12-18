class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int len = prices.size();

        for (int i = 0; i < len; ++i)
            for (int j = i + 1; j < len; ++j)
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;
                }

        return prices;
    }
};
