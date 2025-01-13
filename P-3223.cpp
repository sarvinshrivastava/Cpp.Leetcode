class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> um;

        for (auto x : s) {
            ++um[x];

            if (um[x] >= 3) um[x] -= 2;
        }

        int len = 0;

        for (auto x : um)
            len += x.second;

        return len;
    }
};
