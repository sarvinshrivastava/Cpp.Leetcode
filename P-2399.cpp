class Solution {
public:
    bool checkDistances(string s, vector<int>& dist) {
        vector<int> ndist(26, -1);
        int len = s.size();

        for (int i = 0; i < len; ++i) {
            int idx = s[i] - 'a';

            if (ndist[idx] == -1)
                ndist[idx] = i;

            else if (i - ndist[idx] - 1 != dist[idx])
                    return false;
        }

        return true;
    }
};
