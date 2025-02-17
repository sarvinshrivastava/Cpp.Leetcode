class Solution {
public:
    double separateSquares(vector<vector<int>>& sqs) {
        double total_area = 0.0, low = 0.0, high = 0.0, mid;

        for (const auto& s : sqs) {
            total_area += (double)s[2] * (double)s[2];
            high = max(high, (double)(s[1] + s[2]));
        }

        while(high - low > 1e-6) {
            mid = low + (high - low) / 2.0;
            double cur_area = 0.0;

            for (const auto& s : sqs) {
                if(s[1] + s[2] <= mid)
                    cur_area += (double)s[2] * (double)s[2];
                else if(s[1] < mid)
                    cur_area += (double)s[2] * (double)(mid - s[1]);
            }

            if(cur_area < total_area - cur_area)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
