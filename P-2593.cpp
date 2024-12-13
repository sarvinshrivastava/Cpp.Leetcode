struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first)
            return a.first > b.first;
        else
            return a.second > b.second;
    }
};

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int len = nums.size();
        long long sum = 0;
        vector<int> marked(len, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (int i = 0; i < len; ++i)
            pq.push({nums[i], i});

        while (!pq.empty()) {
            pair <int, int> temp = pq.top(); pq.pop();

            if (marked[temp.second] == 1) continue;
            else {
                marked[temp.second] = 1;
                if (temp.second - 1 >= 0)
                    marked[temp.second - 1] = 1;
                if (temp.second + 1 < len)
                    marked[temp.second + 1] = 1;
                sum += temp.first;
            }
        }

        return sum;
    }
};
