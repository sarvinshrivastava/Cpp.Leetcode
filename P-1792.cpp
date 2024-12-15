struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        double gainA = (double)(a.first + 1) / (a.second + 1) - (double)a.first / a.second;
        double gainB = (double)(b.first + 1) / (b.second + 1) - (double)b.first / b.second;
        return gainA < gainB;
    }
};


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extStuds) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }

        while (extStuds--) {
            auto [p, t] = pq.top();
            pq.pop();
            pq.push({p + 1, t + 1});
        }

        double tRatio = 0.0;
        while (!pq.empty()) {
            auto [p, t] = pq.top();
            pq.pop();
            tRatio += (double)p / t;
        }

        return tRatio / classes.size();
    }
};
