class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            vector <int> preSum (blocks.size() + 1);
    
            preSum[0] = 0;
            for (int i = 1; i < preSum.size(); ++i) {
                if (blocks[i - 1] == 'W')
                    preSum[i] = preSum[i - 1] + 1;
                else
                    preSum[i] = preSum[i - 1];
            }
    
            for (auto p : preSum)
                cout << p << " ";
    
            int i = 0, j = i + k, res = INT_MAX;
            for (; j < preSum.size(); ++j, ++i)
                res = min (res, preSum[j] - preSum[i]);
    
            return res;
        }
    };