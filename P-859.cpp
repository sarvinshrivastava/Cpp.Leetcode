class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;

        int cnt = 0;
        unordered_map<char, pair<int, int>> freqMap;

        for (int i = 0; i < s.size(); ++i) {
            freqMap[s[i]].first++;
            freqMap[goal[i]].second++;

            if (s[i] != goal[i]) {
                cnt++;
                if (cnt > 2)
                    return false;
            }
        }

        if (cnt == 2) {
            for (auto x : freqMap)
                if (x.second.first != x.second.second)
                    return false;
            return true;
        } else if (cnt == 1)
            return false;

        else {
            for (auto x : freqMap)
                if (x.second.first > 1)
                    return true;
            return false;
        }
    }
};
