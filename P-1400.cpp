class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size())
            return false;
        else if (k == s.size())
            return true;

        unordered_map<char, int> um;

        for (auto x : s)
            ++um[x];

        int o_cnt = 0;

        for (auto x : um)
            if (x.second % 2 != 0)
                ++o_cnt;

        if (o_cnt > k)
            return false;
        return true;
    }
};
