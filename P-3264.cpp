struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first > b.first;
        else return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int len = nums.size();

        for (int i = 0; i < len; ++i) pq.push({nums[i], i});

        while (k--) {
            auto [val, i] = pq.top(); pq.pop();
            pq.push({val * multiplier, i});
        }

        while (!pq.empty()) {
            auto [val, i] = pq.top(); pq.pop();
            nums[i] = val;
        }

        return nums;
    }
};
