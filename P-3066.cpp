class mycomparison {
public:
    bool operator()(const long long& lhs, const long long& rhs) {
        return (lhs > rhs);
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long cnt = 0;
        priority_queue<long long, vector<long long>, mycomparison> queue;

        for (auto n : nums)
            queue.push(n);

        while (queue.top() < k) {
            cnt++;
            long long x = queue.top(); queue.pop();
            long long y = queue.top(); queue.pop();

            long long a = min(x, y) * 2 + max(x, y);
            queue.push(a);
        }

        return cnt;
    }
};
