class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        unordered_map<int, int> overall, tp, btm;
        int len = tops.size();

        for (int i = 0; i < len; ++i)
        {
            tp[tops[i]]++;
            btm[bottoms[i]]++;
            overall[tops[i]]++;

            if (tops[i] != bottoms[i])
                overall[bottoms[i]]++;
        }

        vector<int> list;
        for (auto [x, y] : overall)
            if (len <= y)
                list.push_back(x);

        if (list.size() == 0)
            return -1;

        int leastSwap = INT_MAX;
        for (auto l : list)
            leastSwap = min(len - max(tp[l], btm[l]), leastSwap);

        return leastSwap;
    }
};