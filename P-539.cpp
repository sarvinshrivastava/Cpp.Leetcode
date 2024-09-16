class Solution {
public:
    int findMinDifference(vector<string>& tP) {
        int min = 1439;

        sort(tP.begin(), tP.end());

        for (int i = 0; i < tP.size() - 1; i++) {
            int hr1 = stoi(tP[i].substr(0,2)), m1 = stoi(tP[i].substr(3, 2));

            for(int j = 1 + i; j < tP.size(); j++) {
                int hr2 = stoi(tP[j].substr(0,2)), m2 = stoi(tP[j].substr(3, 2));
                int dt = (hr2 - hr1) * 60 + m2 - m1;

                if (dt == 0)
                    return 0;

                if (1440 - dt < dt)
                    dt = 1440 - dt;

                if (dt < min)
                    min = dt;
            }
        }
        return min;
    }
};
