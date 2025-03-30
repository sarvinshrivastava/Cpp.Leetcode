class Solution {
public:
    vector<int> findPeaks(vector<int>& mnt) {
        vector <int> res;
        for (int i = 1; i < mnt.size() - 1; ++i)
            if (mnt[i] > mnt[i - 1] && mnt[i] > mnt[i + 1])
                res.push_back(i);

        return res;
    }
};
