class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Step 1: Sort meetings based on start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Merge intervals efficiently
        vector<pair<int, int>> mergedMeetings;
        int start = meetings[0][0], end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            if (meetings[i][0] <= end + 1)
                end = max(end, meetings[i][1]);
            else {
                mergedMeetings.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        mergedMeetings.push_back({start, end});

        // Step 3: Count total meeting days and subtract from total days
        for (auto& m : mergedMeetings)
            days -= (m.second - m.first + 1);

        return days;
    }
};
