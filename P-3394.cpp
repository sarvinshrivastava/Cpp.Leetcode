class Solution {
public:
    bool checkCuts(vector<vector<int>>& recs, int axis) {
        int gapCnt = 0;

        sort(recs.begin(), recs.end(),
             [axis](const vector<int>& a, const vector<int>& b) {
                 return a[axis] < b[axis];
             });

        int end = recs[0][axis + 2];

        for (int i = 1; i < recs.size(); i++) {
            if (end <= recs[i][axis])
                gapCnt++;

            end = max(end, recs[i][axis + 2]);
        }

        return gapCnt >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& recs) {
        return checkCuts(recs, 0) || checkCuts(recs, 1);
    }
};