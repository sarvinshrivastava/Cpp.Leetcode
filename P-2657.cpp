class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int len = A.size(), cnt = 0;
        vector<int> res(len, 0), freq(len + 1, 0);

        for(int i = 0; i < len; ++i) {
            if (++freq[A[i]] == 2) ++cnt;
            if (++freq[B[i]] == 2) ++cnt;

            res[i] = cnt;
        }

        return res;
    }
};
