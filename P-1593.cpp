class Solution {
public:
    set<string> se;

    int helper(string& s, int start) {
        if (start == s.size()) {
            return 0;
        }

        int maxC = 0;
        string cSub = "";

        for (int i = start; i < s.size(); i++) {
            cSub += s[i];

            if (se.find(cSub) == se.end()) {
                se.emplace(cSub);
                int a = 1 + helper(s, i + 1);
                maxC = (maxC > a) ? maxC : a;
                se.erase(cSub);
            }
        }

        return maxC;
    }

    int maxUniqueSplit(string s) {
        return helper(s, 0);
    }
};
