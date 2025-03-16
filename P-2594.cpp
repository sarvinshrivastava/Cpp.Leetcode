class Solution {
public:
    bool helper(vector<int>& ranks, long long time, int cars) {
        long long total = 0;

        for (int r : ranks)
            total += (long long)floor(sqrt((long double)time / r));

        return total >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        long long high = *min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;
        long long low = 0, ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
        
            if (helper(ranks, mid, cars)) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
            
        }
        
        return ans;
    }
};
