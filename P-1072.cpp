class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freqMap;
        int maxRows = 0;

        for (const auto& row : matrix) {
            string canonical;
            bool flip = row[0];

            for (int val : row) canonical += (val ^ flip) + '0';

            freqMap[canonical]++;
            maxRows = max(maxRows, freqMap[canonical]);
        }

        return maxRows;
    }
};
