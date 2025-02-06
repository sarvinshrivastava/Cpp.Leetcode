class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        unordered_map<char, pair<int, int>> freqMap;

        for (int i = 0; i < s1.size(); ++i) {
            freqMap[s1[i]].first++;
            freqMap[s2[i]].second++;
            
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt > 2)
                    return false;
            }
        }

        for (auto x : freqMap)
            if (x.second.first != x.second.second)
                return false;
        
        return true;
    }
};
