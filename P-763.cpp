class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map <char, pair<int, int>> posOf;

        for (int i = 0; i < s.size(); ++i) {
            char ch =  s[i];

            if (posOf.find(ch) == posOf.end())
                posOf[ch].first = i;

            posOf[ch].second = i;
        }

        vector <pair <int, int> > intervals;
        for (auto [ch, x] : posOf)
            intervals.push_back(x);

        posOf.clear();
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size() - 1; ) {
            if (intervals[i].second >= intervals[i + 1].first) {
                intervals[i].first = min (intervals[i].first, intervals[i + 1].first);
                intervals[i].second = max (intervals[i].second, intervals[i + 1].second);
                intervals.erase(intervals.begin() + i + 1);
            }
            else
                ++i;
        }

        vector<int> result;
        for (auto [x, y] : intervals)
            result.push_back(y - x + 1);

        return result;
    }
};
