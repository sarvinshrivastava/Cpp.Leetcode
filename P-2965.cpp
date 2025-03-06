class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int len = grid.size();
        vector <int> freq (len * len + 1, 0), result;

        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j)
                freq[grid[i][j]]++;


        for (int i = 1; i < freq.size(); ++i)
            if (freq[i] == 2 || freq[i] == 0) {
                result.push_back(i);

                if (result.size() == 2)
                    break;
            }

        if (freq[result[0]] == 0)
            swap(result[0], result[1]);
        return result;
    }
};
