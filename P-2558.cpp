class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue <long long> pq;

        for (auto x : gifts) pq.push(x);

        while (k--) {
            long long e = pq.top(); pq.pop();
            e = floor(sqrt(e));
            pq.push(e);
        }

        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top(); pq.pop();
        }

        return sum;
    }
};
