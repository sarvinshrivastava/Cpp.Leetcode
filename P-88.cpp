class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        a.erase(a.begin() + m, a.end());

        int i = 0, j = 0;
        while (i < a.size() && j < n) {
            if (a[i] >= b[j]) {
                a.insert(a.begin() + i, b[j]);
                ++j;
            }
            ++i;
        }

        while (j < n) {
            a.insert(a.end(), b[j]);
            j++;
        }
            
    }
};