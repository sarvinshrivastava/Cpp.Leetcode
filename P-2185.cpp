class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int plen = pref.size(), cnt = 0;

        for (auto x : words)
            if (x.compare(0, plen, pref) == 0)
                cnt++;

        return cnt;
    }
};
